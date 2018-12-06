using std::vector;

template <typename T>
void set_empty(vector<T>& data)
{
    vector<T> vect;
    data = vect;
}

template <typename T>
T get_empty()
{
    T data;
    set_empty(data);
    return data;
}