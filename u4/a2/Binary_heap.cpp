#include "Binary_heap.hpp"

// use N because it's cleaner than using content.size() with an offset all the time, especially since we work with the dummy element.

/* legend (we work with a binary tree/heap):
 * k/2 = parent node
 * 2k = left child node
 * 2k + 1 = right child node
 */

Binary_heap::Binary_heap()
{
    N = 0;
    // add dummy element. Since we don't increase N for it, it's basically ignored anyway.
    Apple dummy = Apple(0,0);
    content.push_back(dummy);
}

bool Binary_heap::is_empty()
{
    return N == 0;
}

void Binary_heap::insert(Apple a)
{
    content.push_back(a); // add apple to the bottom of the heap
    N++; // raise counter
    swim(N); // put the added object into the right spot in the binary heap
}

Apple Binary_heap::del_max()
{
    Apple max = content[1]; // save max value for return
    exch(1, N--); // swap top with bottom node
    sink(1); // fix order violation
    content.pop_back(); // remove max value (which is at the bottom) from the heap
    return max; // return saved value
}


void Binary_heap::exch(int i, int j)
{
    Apple tmp = content[i];
    content[i] = content[j];
    content[j] = tmp;
}

void Binary_heap::swim(int k) // push our new add element up the binary tree
{
    // swim element up as long as it's not the top of the binary tree and the parent node is smaller than our node (bigger apples need to go up)
    while (k > 1 && content[k/2] < content[k])
    {
        exch(k, k/2);
        k = k/2; // continue on upper level in next loop iteration
    }
}

void Binary_heap::sink(int k) // sink the exchanged element down the heap to its correct spot
{
    while (2*k <= N) // "as long as we have a child node..."
    {
        int j = 2*k; // set counter j to child node
        if (j < N && content[j] < content[j+1]) // check if can (and should) proceed on the right side. If not, we use the left side.
            j++;
        if (!(content[k] < content[j])) // if our element doesn't belong further down the heap (if it's bigger than both childs), break out of the loop.
            break;
        exch(k, j);  // if it belongs down there, do the swapping...
        k = j; // ...and continue from there on in the next loop iteration
    }
}

