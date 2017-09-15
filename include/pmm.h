#ifndef INCLUDE_PMM_H_
#define INCLUDE_PMM_H_

#include "multiboot.h"

//线程栈的大小
#define STACK_SIZE 8192

//支持的最大物理内存（512MB）
#define PMM_MAX_SIZE 0x20000000

//物理内存页框大小(4KB)
#define PMM_PAGE_SIZE 0x1000

// 最多支持的物理页面个数
#define PAGE_MAX_SIZE (PMM_MAX_SIZE/PMM_PAGE_SIZE)

//页掩码按照4096字节对齐
#define PHY_PAGE_MASK 0xFFFFF000

//内核文件在内存中的起始和结束位置
//在链接器脚本中定义
extern uint8_t kern_start[];
extern uint8_t kern_end[];

// 内核栈的栈顶
extern uint32_t kern_stack_top;

//动态分配物理内存页总数
extern uint32_t phy_page_count;

//输出BIOS提供的物理内存布局
void show_memory_map();

//初始化物理内存管理
void init_pmm();

//返回一个内存页的物理地址
uint32_t pmm_alloc_page();

//释放申请的内存
void pmm_free_page(uint32_t p);


#endif