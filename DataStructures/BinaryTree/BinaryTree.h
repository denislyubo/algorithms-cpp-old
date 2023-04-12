#include <iostream>

#pragma once

template<class T>
class BinaryTree
{
template<class T>
struct Node
{
  Node *left;
  Node *right;
  Node *p;
  T key;
};

int FindMidIndex(std::vector<T> &inputData, int lo, int hi);
void ConstructTree(std::vector<T> &inputData, int lo, int hi, Node<T> *node);
void DeleteTree( Node<T> *node);
void InorderTreeWalk(Node<T> *node);
Node<T> *TreeSearch(Node<T> *node, T k);
T TreeMinimum(Node<T> *node);
T TreeMaximum(Node<T> *node);
T TreeSuccessor(Node<T> *node);

public:
  BinaryTree(std::vector<T> &inputData);
  ~BinaryTree();
  void InorderTreeWalk();
  void TreeSearch(T k);
  T TreeMinimum();
  T TreeMaximum();
  T TreeSuccessor(T key);
  void TreeInsert(T key);
  bool DeleteNode(T key);

private:
  Node<T> *m_pRoot;
};

template<class T>
int BinaryTree<T>::FindMidIndex(std::vector<T> &inputData, int lo, int hi)
{
  int i = lo;
  int j = hi + 1;

  while (true)
  {
    while (inputData[++i] < inputData[lo])
    {
      if (i == hi)
        break;
    }

    while (inputData[lo] < inputData[--j])
    {
      if (j == lo)
        break;
    }

    if (i >= j)
      break;

    T temp = inputData[i];
    inputData[i] = inputData[j];
    inputData[j] = temp;
  }

  T temp = inputData[lo];
  inputData[lo] = inputData[j];
  inputData[j] = temp;

  return j;
}

template<class T>
void BinaryTree<T>::ConstructTree(std::vector<T> &inputData, int lo, int hi, Node<T> *node)
{
  if (lo >= hi)
  {
    node->key = inputData[lo];
    node->left = NULL;
    node->right = NULL;
    return;
  }

  int mid = FindMidIndex(inputData, lo, hi);
  node->key = inputData[mid];
  
  if (mid > lo)
  {
    Node<T> *left = new Node<T>;
    node->left = left;
    left->p = node;
    ConstructTree(inputData, lo, mid - 1, left);
  }
  else
    node->left = NULL;

  if (mid < hi)
  {
    Node<T> *right = new Node<T>;
    node->right = right;
    right->p = node;
    ConstructTree(inputData, mid + 1, hi, right);
  }
  else
    node->right = NULL;
}

template<class T>
void BinaryTree<T>::DeleteTree(Node<T> *node)
{
  if (node != NULL)
  {
    DeleteTree(node->left);
    DeleteTree(node->right);

    delete node;
  }
}

template<class T>
BinaryTree<T>::BinaryTree(std::vector<T> &inputData)
{
  m_pRoot = new Node<T>;
  m_pRoot->p = NULL;

  ConstructTree(inputData, 0, (int)inputData.size() - 1, m_pRoot);
}

template<class T>
BinaryTree<T>::~BinaryTree()
{
  DeleteTree(m_pRoot);
}

template<class T>
void BinaryTree<T>::InorderTreeWalk(Node<T> *node)
{
  if (node != NULL)
  {
    InorderTreeWalk(node->left);
    std::cout << node->key << std::endl;
    InorderTreeWalk(node->right);
  }
}

template<class T>
void BinaryTree<T>::InorderTreeWalk()
{
  InorderTreeWalk(m_pRoot);
}

template<class T>
typename BinaryTree<T>::Node<T> *BinaryTree<T>::TreeSearch(Node<T> *node, T k)
{
  if (node == NULL)
    return NULL;

  if (node->key == k)
  {
    std::cout << k << std::endl;
    return node;
  }

  std::cout << node->key << std::endl;
  if (k < node->key)
    TreeSearch(node->left, k);
  else
    TreeSearch(node->right, k);
}

template<class T>
void BinaryTree<T>::TreeSearch(T k)
{
  std::cout << "Tree search path:\n";
  TreeSearch(m_pRoot, k);
}

template<class T>
T BinaryTree<T>::TreeMinimum(Node<T> *node)
{
  while (node->left != NULL)
  {
    node = node->left;
  }

  if (node != NULL)
    return node->key;
  else return T(-1);
}

template<class T>
T BinaryTree<T>::TreeMinimum()
{
  return TreeMinimum(m_pRoot);
}

template<class T>
T BinaryTree<T>::TreeMaximum(Node<T> *node)
{
  while (node->right != NULL)
  {
    node = node->right;
  }

  if (node != NULL)
    return node->key;
  else return T(-1);
}

template<class T>
T BinaryTree<T>::TreeMaximum()
{
  return TreeMaximum(m_pRoot);
}

template<class T>
T BinaryTree<T>::TreeSuccessor(Node<T> *node)
{
  if (node->right != NULL)
    return TreeMinimum(node->right);

  Node<T> *y = node->p;

  while (y != NULL && node == y->right)
  {
    node = y;
    y = y->p;
  }

  return y->key;
}

template<class T>
T BinaryTree<T>::TreeSuccessor(T key)
{
  Node<T> *searchRes = TreeSearch(m_pRoot, key);

  if (searchRes)
    return TreeSuccessor(searchRes);
  else
    return T(-1);
}

template<class T>
void BinaryTree<T>::TreeInsert(T key)
{
  Node<T> *insertionNode = new Node<T>;
  Node<T> *y = NULL, *x = m_pRoot;

  while (x != NULL)
  {
    y = x;
    if (key < x->key)
      x = x->left;
    else
      x = x->right;
  }

  Node<T> *z = new Node<T>;
  z->key = key;
  z->left = z->right = NULL;

  z->p = y;

  if (y == NULL)
    m_pRoot = z;
  else
    if (z->key < y->key)
      y->left = z;
    else
      y->right = z;
}

template<class T>
bool BinaryTree<T>::DeleteNode(T key)
{
  Node<T> *z = TreeSearch(m_pRoot, key);

  if (z == NULL)
    return false;

  Node<T> *y = NULL, *x = NULL;
  
  if (z->left == NULL || z->right == NULL)
    y = z;
  else
    y = TreeSuccessor(z);

  if (y->left != NULL)
    x = y->left;
  else
    x = y->right;

  if (x != NULL)
    x->p = y->p;

  if (y->p == NULL)
    m_pRoot = x;
  else if (y == y->p->left)
    y->p->left = x;
  else
    y->p->right = x;

  if (y != z)
    z->key = y->key;

  return true;
}

