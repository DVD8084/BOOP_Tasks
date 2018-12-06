#ifndef ARCHIVE_H
#define ARCHIVE_H

#include <archive.h>
#include <archive_entry.h>

int extract(const char*);

int copy_data(struct archive*, struct archive*);

#endif /* ARCHIVE_H */

