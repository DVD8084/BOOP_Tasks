template <typename T>
void print_data(std::vector<T> data)
{
    cout << "[";
    for (int i = 0; i < data.size(); i++)
    {
        print_data(data[i]);
        if (i < data.size() - 1)
        {
            cout << "; ";
        }
    }
    cout << "]";
}