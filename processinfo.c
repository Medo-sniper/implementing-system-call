#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/syscalls.h>
#include <linux/file.h> 
#include <linux/fs.h>
#include <linux/fcntl.h> 
#include <asm/uaccess.h> 
#include <uapi/asm-generic/errno-base.h>



asmlinkage long sys_processinfo(void) {
           
	struct task_struct *proces;

	for_each_process(proces)
	{
                        // Process Name
			printk("Process: %s\n", proces->comm);  
			
			// Process PID
			printk("PID Number: %ld\n", (long)proces->pid); 
			
			// Process State
			printk("Process State: %ld\n", (long)proces->state); 
			
			// Process Priority
			printk("Priority: %ld\n", (long)proces->prio); 
			
			// Process RT_Priority
			printk("RT_Priority: %ld\n", (long)proces->rt_priority); 
	
			// Process Static Priority
			printk("Static Priority: %ld\n", (long)proces->static_prio); 
			
			// Process Normal Priority
			printk("Normal Priority: %ld\n", (long)proces->normal_prio);  
			
                        if(proces->parent) {
                              // Parent Process Name
                              printk("Parent process: %s\n", proces->parent->comm); 
                              
                              // Parent Process PID  
                              printk("PID_Number: %ld \n\n", (long)task_pid_nr(proces->parent)); 
                        }
			
		printk("\n\n");
	}

        printk("============================\n");
        printk("\n\nAuthor: Ahmad Banisaeed.\n");
        printk("\n***System Call processinfo***\n");
        printk("============================\n");
        
	return 0;
}

