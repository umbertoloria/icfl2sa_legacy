#ifndef CUSTOM_PREFIX_TREE_H_INCLUDED
#define CUSTOM_PREFIX_TREE_H_INCLUDED

#include <string>
#include <vector>
#include <unistd.h>
#include "generic_vector.h"
#include <mutex>
#include <pthread.h>
#include <thread>
#include <malloc.h>
#include <string.h>
#include <map>
#include <unordered_map>
#include <cstring>
#include "merge.h"
#include <omp.h>
#include "second_phase.h"


//#include <jthread>

#define MAX_THREADS 4

using namespace std;

struct nodes_vector;

unsigned long last_substring_in_map(const char *suffix,int suffix_len,std::unordered_map<size_t,std::vector<suffix_tree_node*>>& m);

suffix_tree_node* build_suffix_tree_node(suffix_tree_node* father,const char* suffix,int suffix_len);
suffix_tree_node* build_suffix_tree_node_2(suffix_tree_node* father,const char* suffix,int suffix_len);
suffix_tree_node* build_suffix_tree_orphan_node(const char* suffix,int suffix_len);
//Non fa i return(cosa bella)
void stampa_suffix_tree(suffix_tree_node* root);

void delete_suffix_tree_node(suffix_tree_node* x);

nodes_vector* init_nodes_vector(size_t size);
bool add_in_nodes_vector(nodes_vector* x,suffix_tree_node* element);
int LCP(char* w, int index1,int index2);
int LCP_with_given_strings(const char* x,const char* y);
int LCP_with_given_strings_2(const char* x,const char* y,int max_len);
int LCP_from_same_string(const char* piccola,const char* grande,int n);

//utils replicate
int linear_search(vector<suffix_tree_node*>& n_vector,int root_size, const char* x,int suffix_len);
void quicksort_of_nodes_local(nodes_vector* x, int start, int end);
int binarySearch_4_with_redundancy(vector<suffix_tree_node*> n_vector, const char* x,int suffix_len, int low, int high,int* is_not_equal);
int binarySearch_4_with_redundancy_2(nodes_vector* n_vector,int root_size, const char* x,int suffix_len, int low, int high,bool* is_equal);
int binarySearch_4_with_redundancy_2_iterative(vector<suffix_tree_node*>& n_vector,int root_size, const char* x,int suffix_len, int low, int high,int* is_not_equal);
int binarySearch_4_with_redundancy_3_iterative(vector<suffix_tree_node*> n_vector,int root_size, const char* x,int suffix_len, int low, int high,int* is_not_equal);
void print_nodes_vector(nodes_vector* n_vec);
void print_nodes_vector_2(std::vector<suffix_tree_node*> n_vec);
void add_in_order_4(std::vector<suffix_tree_node*>& sons,suffix_tree_node* node,int starting_position);
void add_in_order_5(vector<suffix_tree_node*>& sons,suffix_tree_node* node,int starting_position);
void add_in_order_6(vector<suffix_tree_node*>* sons,suffix_tree_node* node,int starting_position);

alberello* init_alberello();
//DA USARE SOLO QUANDO LA ROOTS È UGUALE ALLE FOGLIE
void join_two_alberelli(suffix_tree_node* a,suffix_tree_node* b);
void join_two_alberelli_2(suffix_tree_node* a,suffix_tree_node* b,suffix_tree_node** res);
void join_two_alberelli_3(suffix_tree_node* a,suffix_tree_node* b,suffix_tree_node** res);
void join_two_alberelli_3_2(suffix_tree_node* a,suffix_tree_node* b,suffix_tree_node** res);
void join_two_alberelli_4(suffix_tree_node* a,suffix_tree_node* b,suffix_tree_node** res,const char* S,std::vector<int> icfl_list);
suffix_tree_node* join_two_alberelli_4(suffix_tree_node* a,suffix_tree_node* b);
void join_two_alberelli_5(suffix_tree_node* a,suffix_tree_node* b,suffix_tree_node** res,std::unordered_map<size_t,std::vector<suffix_tree_node*>>& m,std::mutex& mutex_m);
void join_n_alberelli(suffix_tree_node** roots,int k,suffix_tree_node** res_tree);
void join_n_alberelli_multithreading(suffix_tree_node** roots,int k,suffix_tree_node** res_tree);
void join_n_alberelli_multithreading_2(suffix_tree_node** roots,int k,suffix_tree_node** res_tree);
void join_n_alberelli_omp(suffix_tree_node** roots,int k,suffix_tree_node** res_tree,const char* S,std::vector<int>& icfl_list);
void join_n_alberelli_omp_2(suffix_tree_node** roots,int k,suffix_tree_node** res_tree,std::unordered_map<size_t,std::vector<suffix_tree_node*>>& m,std::mutex& mutex_m);
void join_k_alberelli(suffix_tree_node** roots,int start,int end);
void join_k_alberelli_2(suffix_tree_node** roots,suffix_tree_node** res,int start,int end);
void join_k_alberelli_2_openmp(suffix_tree_node** roots,suffix_tree_node** res,int start,int end);
void join_n_alberelli_omp_inner(suffix_tree_node** roots,suffix_tree_node** temp_res,int* k,const char* S,std::vector<int>& icfl_list);
void join_n_alberelli_omp_inner_2(suffix_tree_node** roots,suffix_tree_node** temp_res,int* k,std::unordered_map<size_t,std::vector<suffix_tree_node*>>& m,std::mutex& mutex_m);
void add_node_in_node_sons_3(suffix_tree_node* opt_padre,suffix_tree_node* figlio,int index,int is_not_equal);
void add_node_in_node_sons_4(suffix_tree_node* opt_padre,suffix_tree_node* figlio);
void add_node_in_node_sons_5(suffix_tree_node* opt_padre,suffix_tree_node* figlio,int index,int is_not_equal);
void add_suffix_in_node_sons_2(suffix_tree_node* root,const char* S,const char* suffix,int suffix_len,int suffix_index,vector<int>& icfl_list,vector<int>& custom_icfl_list,int lenght_of_word,vector<int>& is_custom_vec,vector<int>& factor_list);
void add_suffix_in_node_sons_4(suffix_tree_node* root,const char* S,const char* suffix,int suffix_len,int suffix_index,vector<int>& icfl_list,vector<int>& custom_icfl_list,int lenght_of_word,vector<int>& is_custom_vec,vector<int>& factor_list);
suffix_tree_node* add_suffix_in_node_sons_3(suffix_tree_node* root,const char* suffix,int suffix_len,int suffix_index);
suffix_tree_node* search_father_for_suffix_2(suffix_tree_node* root,const char* suffix,int suffix_len,int* index,int* is_not_equal);
suffix_tree_node* search_father_for_suffix_2_iterative(suffix_tree_node* root,const char* suffix,int suffix_len,int* index,int* is_not_equal);
suffix_tree_node* search_father_for_suffix_3_iterative(suffix_tree_node* root,const char* suffix,int suffix_len);
suffix_tree_node* search_father_for_suffix_3_iterative_2(suffix_tree_node* root,const char* suffix,int suffix_len,int* index,int* is_not_equal);
suffix_tree_node* search_father_for_suffix_3_iterative_3(suffix_tree_node* root,const char* suffix,int suffix_len);
suffix_tree_node* search_father_for_suffix_4(const char* suffix,int suffix_len,std::unordered_map<size_t,std::vector<suffix_tree_node*>>& m,std::mutex& mutex_m);
void add_node_in_node_sons_5_map(std::vector<suffix_tree_node*>& opt_padre_sons,suffix_tree_node* figlio);


void merge_custom_array_of_indexes(const char* S,vector<int>& icfl_list,suffix_tree_node* alberello,std::vector<int> &is_custom_suffix, std::vector<int> &factor_list);
#endif