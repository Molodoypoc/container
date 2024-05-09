#include "IntegerArray.h"
#include <iostream>

int main()
{
    try
    {
        IntegerArray arr(5);
        arr[0] = 1;
        arr[1] = 4;
        arr[2] = 9;
        arr[3] = 1;
        arr[4] = 3;
        arr.insert(4, 6);
        arr.remove(0);
        arr.inserts(6);
        arr.inserte(1);
        for (size_t i = 0; i < arr.getSize(); i++) {
            std::cout << i << " - " << arr[i] << std::endl;
        }
    }
    catch (const bad_length& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (const bad_range& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}