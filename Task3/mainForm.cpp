#include "mainForm.h"

using std::vector;

mainForm::mainForm() {
    widget.setupUi(this);
    widget.contents->setColumnWidth(0, 250);
}

mainForm::~mainForm() {
}

void mainForm::on_actionOpen_File_triggered() {
    filePath = QFileDialog::getOpenFileName(this, "Open Archive", "", "Archive Files (*.zip *.rar *.tar *.iso *.cab)");
    if (!filePath.isEmpty()) {
        /* open archive and read all entries */
        widget.contents->clear();
        //widget.actionOpen_File->setText(filePath);
        struct archive *a;
        struct archive_entry *entry;
        int r;
        a = archive_read_new();
        archive_read_support_filter_all(a);
        archive_read_support_format_all(a);
        r = archive_read_open_filename(a, filePath.toStdString().c_str(), 10240);
        if (r != ARCHIVE_OK)
            exit(1);
        while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
            QString path, size;
            path = archive_entry_pathname(entry);
            size.setNum(archive_entry_size(entry));
            if (size == "0") {
                size = "";
            }
            addTreeRoot(path, size);
            archive_read_data_skip(a);
        }
        r = archive_read_free(a);
        if (r != ARCHIVE_OK)
            exit(1);
    }
    widget.contents->sortItems(0, Qt::AscendingOrder);
    /* rearrange entries into a tree */
    vector <QTreeWidgetItem*> treeLevels;
    int itemCount = 0;
    while (itemCount < widget.contents->topLevelItemCount()) {
        QTreeWidgetItem *item = widget.contents->topLevelItem(itemCount);
        int level = 0;
        QString subpath = item->text(0);
        QTreeWidgetItem *subitem = widget.contents->topLevelItem(itemCount - 1);
        while (subitem) {
            if (subitem->text(0) == subpath.left(subitem->text(0).size())) {
                level++;
                if (subpath.size() > subitem->text(0).size() + 1) {
                    subpath = subpath.right(subpath.size() - subitem->text(0).size() - 1);
                }
                if (subitem->childCount()) {
                    subitem = subitem->child(subitem->childCount() - 1);
                } else {
                    subitem = nullptr;
                }
            } else {
                break;
            }
        }
        treeLevels.resize(level);
        level = treeLevel(item->text(0));
        if (level) {
            if (level > treeLevels.size()) {
                QString path = item->text(0);
                QTreeWidgetItem *subfolder = new QTreeWidgetItem();
                for (int i = 0; i < level - treeLevels.size() - 1; i++) {
                    path = path.left(path.size() - lastPathElement(path).size() - isFolder(path));
                    subfolder->setText(0, lastPathElement(path));
                    QTreeWidgetItem *folder = new QTreeWidgetItem();
                    folder->addChild(subfolder);
                    subfolder = folder;
                }
                path = path.left(path.size() - lastPathElement(path).size() - isFolder(path));
                subfolder->setText(0, lastPathElement(path));
                if (treeLevels.size()) {
                    treeLevels[treeLevels.size() - 1]->addChild(subfolder);
                } else {
                    widget.contents->insertTopLevelItem(itemCount, subfolder);
                    itemCount++;
                }
                int size = treeLevels.size();
                for (int i = 0; i < level - size - 1; i++) {
                    treeLevels.push_back(subfolder);
                    subfolder = subfolder->child(0);
                }
                treeLevels.push_back(subfolder);
            }
            treeLevels.push_back(addTreeChild(treeLevels[level - 1], lastPathElement(item->text(0)), item->text(1)));
            delete item;
        } else {
            treeLevels.clear();
            treeLevels.push_back(item);
            item->setText(0, lastPathElement(item->text(0)));
            itemCount++;
        }
    }
}

void mainForm::on_actionUnpack_triggered() {
    QString dir = QFileDialog::getExistingDirectory(this, "Open Directory", "", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) {
        _chdir(dir.toStdString().c_str());
        if(!extract(filePath.toStdString().c_str())) {
            if (filePath.right(4) == ".zip") {
                QMessageBox msg(QMessageBox::Critical, "Error", "Unsupported zip compression.", QMessageBox::Ok);
                msg.exec();
            }
            QMessageBox msg(QMessageBox::Warning, "Warning", "libarchive returned an unusual value.\nThis might indicate an error.", QMessageBox::Ok);
            msg.exec();
        }
    }
}

QTreeWidgetItem *mainForm::addTreeRoot(QString name, QString description)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(widget.contents);
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    return treeItem;
}

QTreeWidgetItem *mainForm::addTreeChild(QTreeWidgetItem *parent, QString name, QString description)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0, name);
    treeItem->setText(1, description);
    parent->addChild(treeItem);
    return treeItem;
}

bool mainForm::isFolder(QString path) {
    return path[path.size() - 1] == '/';
}

int mainForm::treeLevel(QString path) {
    int level = 0;
    for (int i = 0; i < path.size(); i++) {
        if (path[i] == '/') {
            ++level;
        }
    }
    return level - isFolder(path);
}

QString mainForm::lastPathElement(QString path) {
    for (int i = 1; i < path.size(); i++) {
        if (path[path.size() - i - 1] == '/') {
            return path.right(i).left(i - (path[path.size() - 1] == '/'));
        }
    }
    return path.left(path.size() - (path[path.size() - 1] == '/'));
}