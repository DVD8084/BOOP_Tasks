template <typename T>
StackStd<T>::StackStd()
{
}

template <typename T>
StackStd<T>::StackStd(T data)
{
    std_stack.push(data);
}

template <typename T>
void StackStd<T>::print()
{
    stack<T> stack_copy = std_stack;
    while (stack_copy.size())
    {
        print_data(stack_copy.top());
        stack_copy.pop();
        if (stack_copy.size())
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
int StackStd<T>::push(T new_data)
{
    std_stack.push(new_data);
    return 1;
}

template <typename T>
T StackStd<T>::peek()
{
    if (std_stack.size())
    {
        return std_stack.top();
    }
    else
    {
        return get_empty<T>();
    }
}

template <typename T>
T StackStd<T>::pop()
{
    if (std_stack.size())
    {
        T popped = std_stack.top();
        std_stack.pop();
        return popped;
    }
    else
    {
        return get_empty<T>();
    }
}

template <typename T>
void StackStd<T>::fill_random(int size)
{
    stack<T> new_stack;
    std_stack = new_stack;
    for(int i = 0; i < size; i++)
    {
        std_stack.push(get_random<T>());
    }
}
