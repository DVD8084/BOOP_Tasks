using std::vector;

/**
 *  @brief  Initializes %std::vector as a default vector. 
 *  @param  data  The initialized %std::vector.
 */
template <typename T>
void set_empty(vector<T>& data)
{
    vector<T> vect;
    data = vect;
}

/**
 *  @brief  Returns an empty value for any supported type.
 */
template <typename T>
T get_empty()
{
    T data;
    set_empty(data);
    return data;
}