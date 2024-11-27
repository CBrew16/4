//
// Created by Cameron Brewster on 2024-11-20.
//
// huffman_tree.h: Define the structure and operations for the Huffman Tree.
// priority_queue.h: Define the priority queue for storing nodes.
// compression.h: Functions for compressing files.
// decompression.h: Functions for decompressing files.
// file_utils.h: Utility functions for reading and writing files.


#ifndef HUFFMANN_TREE_H
#define HUFFMANN_TREE_H
#define MAX 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct {
 int index;
 unsigned int weight;
} node_t;

// The HuffmanNode definition
typedef struct HuffmanNode {
 int frequency;
 struct HuffmanNode* left;
 struct HuffmanNode* right;
 char data;
} HuffmanNode;


typedef struct QueueNode {
 HuffmanNode *node;
 struct QueueNode* next;      // Pointer to the next node
} QueueNode;
typedef struct {
 QueueNode* front;            // Pointer to the front of the queue
 QueueNode* rear;
 // Pointer to the rear of the queue
} Queue;


// Function declarations
HuffmanNode* createLeafNode(char data, int frequency);
HuffmanNode* createInternalNodes(HuffmanNode* left, HuffmanNode* right);
HuffmanNode* buildHuffmanTree(Queue* queue);
void freeHuffmanTree(HuffmanNode *root);

void getCode(HuffmanNode *root, char codes[256][MAX], char* currentCode, int depth);


// Function declarations in huffmann_tree.h
void HuffmanCodes(HuffmanNode *root, char codes[256][MAX]);


void compress(const char *filename, char *compressed, HuffmanNode *root, char codes[256][MAX]);

void decompress(const char *compressed, char *decompressed, HuffmanNode *root);


// Queue operations
void initQueue(Queue* q);
void priorityEnqueue(Queue* q, HuffmanNode* node);
HuffmanNode* priorityDequeue(Queue* q);
void freeQueue(Queue* q);

// File operations
void countFrequencies(const char *filename, node_t *nodes, int *uniqueCharCount);

#endif //HUFFMANN_TREE_H
