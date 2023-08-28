/*

Title: Work Queue
Source: https://docs.zephyrproject.org/latest/kernel/services/threads/workqueue.html


*/

#include <zephyr/kernel.h>

#define OUR_QUEUE_SIZE  1024 // 1.2 Set Queue Size
#define OUR_QUEUE_PRIORITY 5 // 1.3 Set Queue Priority

K_THREAD_STACK_DEFINE(our_queue_area, OUR_QUEUE_SIZE); //1.1 Define a Queue

struct k_work_q our_work_q;  //1.0 create a queue

struct k_work our_work; // 2.0 create a work

static void our_work_fn(struct k_work *work) //2.1 make a work function
{
    printk("I am the first task in the queue.");
}


void main(void)
{

    k_work_queue_init(&our_work_q); // 1.4 initialize a queue

    k_work_queue_start(&our_work_q, our_queue_area, K_THREAD_STACK_SIZEOF(our_queue_area), OUR_QUEUE_PRIORITY, NULL); //1. 5 Start a queue

    k_work_init(&our_work, our_work_fn); //2.2 initialize a work

    k_work_submit_to_queue(&our_work_q, &our_work); //2.3 submit the work to the queue

}
