#include "queue.h"

#include <stdlib.h>

#define MAX_QUEUE 256

static uint8_t _queue[MAX_QUEUE / 4];
static uint16_t _queue_size = 1;

static unsigned int
find_srand()
{
    return 1;  // TODO
}

void
queue_init()
{
    srand(find_srand());
    for (int i = 0; i < (MAX_QUEUE / 4); ++i)
        _queue[i] = rand();
    _queue_size = 1;
}

uint8_t
queue_size()
{
    return _queue_size;
}

uint8_t
queue_item(uint8_t i)
{
    return ((_queue[i / 4]) >> ((i % 4) * 2)) & 0b11;
}

void
queue_increase()
{
    ++_queue_size;
}

// vim:st=4:sts=4:sw=4:expandtab
