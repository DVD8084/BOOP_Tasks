template <typename T>
StackArray<T>::StackArray()
{
}

template <typename T>
StackArray<T>::StackArray(T data)
{
    stack[0] = data;
    stack_size = 1;
}

template <typename T>
void StackArray<T>::print()
{
    for (int i = 0; i < stack_size; i++)
    {
        print_data(stack[i]);
        if (i < stack_size - 1)
        {
            print_data(" <- ");
        }
        else
        {
            print_data("\n");
        }
    }
}

template <typename T>
int StackArray<T>::push(T new_data)
{
    if (stack_size < MAX_ARRAY_SIZE)
    {
        stack[stack_size++] = new_data;
        return 1;
    }
    else
    {
        return 0;
    }
}

template <typename T>
T StackArray<T>::peek()
{
    if (stack_size)
    {
        return stack[stack_size - 1];
    }
    else
    {
        return get_empty<T>();
    }
}

template <typename T>
T StackArray<T>::pop()
{
    if (stack_size)
    {
        return stack[--stack_size];
    }
    else
    {
        return get_empty<T>();
    }
}

template <typename T>
void StackArray<T>::fill_random(int size)
{
    stack_size = 0;
    while(stack_size < size && size < MAX_ARRAY_SIZE)
    {
        set_random(stack[stack_size]);
        ++stack_size;
    }
}
