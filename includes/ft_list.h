#ifndef FT_LIST_H
#define FT_LIST_H

#include <stdlib.h>

#define DEFINE_LIST_HEADERS(type)                                            \
    typedef struct s_list_##type                                             \
    {                                                                        \
        type data;                                                           \
        struct s_list_##type *next;                                          \
    } t_list_##type;                                                         \
                                                                             \
    t_list_##type *lst_add_front_##type(t_list_##type **lst, type *data); \
    t_list_##type *lst_add_back_##type(t_list_##type **lst, type *data);  \
    void lst_clear_##type(t_list_##type **lst);                           \
    void lst_foreach_##type(t_list_##type *lst, void (*f)(type *));

#define DEFINE_LIST_FUNCTIONS(type)                                   \
    static t_list_##type *lst_new_##type(type *data)               \
    {                                                                 \
        t_list_##type *new;                                           \
                                                                      \
        new = malloc(sizeof(t_list_##type));                          \
        if (new == NULL)                                              \
            return (NULL);                                            \
        new->data = *data;                                            \
        new->next = NULL;                                             \
        return (new);                                                 \
    }                                                                 \
                                                                      \
    t_list_##type *lst_add_front_##type(t_list_##type **lst, type *data) \
    {                                                                 \
        t_list_##type *new;                                           \
                                                                      \
        new = lst_new_##type(data);                                \
        if (new == NULL)                                              \
            return (NULL);                                            \
        new->next = *lst;                                             \
        *lst = new;                                                   \
        return (new);                                                 \
    }                                                                 \
                                                                      \
    t_list_##type *lst_add_back_##type(t_list_##type **lst, type *data) \
    {                                                                 \
        t_list_##type *new;                                           \
        t_list_##type *last;                                          \
                                                                      \
        new = lst_new_##type(data);                                \
        if (new == NULL)                                              \
            return (NULL);                                            \
        if (*lst == NULL)                                             \
        {                                                             \
            *lst = new;                                               \
            return (new);                                             \
        }                                                             \
        last = *lst;                                                  \
        while (last->next != NULL)                                    \
            last = last->next;                                        \
        last->next = new;                                             \
        return (new);                                                 \
    }                                                                 \
                                                                      \
    void lst_clear_##type(t_list_##type **lst)                     \
    {                                                                 \
        t_list_##type *tmp;                                           \
                                                                      \
        while (*lst != NULL)                                          \
        {                                                             \
            tmp = *lst;                                               \
            *lst = (*lst)->next;                                      \
            free(tmp);                                                \
        }                                                             \
    }                                                                 \
                                                                      \
    void lst_foreach_##type(t_list_##type *lst, void (*f)(type *)) \
    {                                                                 \
        while (lst != NULL)                                           \
        {                                                             \
            f(&lst->data);                                            \
            lst = lst->next;                                          \
        }                                                             \
    }
    
#endif