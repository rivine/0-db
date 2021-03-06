#ifndef __ZDB_HOOK_H
    #define __ZDB_HOOK_H

    // a hook is called when an external application/script
    // is provided at runtime, this hook executable
    // will be executed in background for different actions
    typedef struct hook_t {
        size_t argc;    // length or arguments
        char **argv;    // arguments

        size_t argidx;  // current argument index (used for fillin)

    } hook_t;

    hook_t *hook_new(char *name, size_t argc);
    int hook_append(hook_t *hook, char *argument);
    pid_t hook_execute(hook_t *hook);
    int hook_execute_wait(hook_t *hook);
    void hook_free(hook_t *hook);

    // need to be called periodicly to cleanup zombies
    void libzdb_hooks_cleanup();
#endif
