#include "lib.h"

String clone(String *string) {
  char *new_elem = malloc(string->size);

  for (size_t i = 0; i < string->size; i++) {
    new_elem[i] = string->elem[i];
  }

  return (String){
      .size = string->size,
      .elem = new_elem,
  };
}

String create_string(char *elem, size_t size) {
  char *new_elem = malloc(size);
  for (size_t i = 0; i < size; i++) {
    new_elem[i] = elem[i];
  }

  return (String){
      .size = size,
      .elem = new_elem,
  };
}

kdTree create_kdTree() {
  kdTree retorno = (kdTree){
      .root = NULL,
      .number_elements = 0,
  };
  return retorno;
}

Node *_create_node() {
  Node *retorno = malloc(sizeof(Node));
  *retorno = (Node){
      .point = _create_point(0.0, 0.0),
      .Obj = NULL,
      .father = NULL,
      .left = NULL,
      .right = NULL,
  };
  return retorno;
}

Point _create_point(const double x, const double y) {
  return (Point){
      .x = x,
      .y = y,
  };
}

bool insert_element(kdTree *tree, const Point point, const size_t size_props,
                    void *element) {
  if (tree->root == NULL) {
    tree->root = (Node *)malloc(sizeof(Node));
    if (tree->root == NULL) {
      exit(1);
    }
    void *new_element = malloc(size_props);
    if (new_element == NULL) {
      exit(1);
    }
    memcpy(new_element, element, size_props);
    *(tree->root) = (Node){
        .point = point,
        .Obj = element,
        .right = NULL,
        .left = NULL,
        .father = NULL,
    };
    return true;
  }
  if (tree->root != NULL) {
    return _insert_element_child(tree->root, point, size_props, element, 1);
  }
  return false;
}

bool _insert_element_child(Node *node, const Point point,
                           const size_t size_props, void *element,
                           const int split_case) {
  if (split_case % 2 == 0) {
    if (node->point.y < point.y) {
      if (node->right == NULL) {
        node->right = (Node *)malloc(sizeof(Node));
        if (node->right == NULL) {
          exit(1);
        }
        void *new_element = malloc(size_props);
        memcpy(new_element, element, size_props);
        *(node->right) = (Node){
            .point = point,
            .Obj = element,
            .right = NULL,
            .left = NULL,
            .father = node,
        };
        return true;
      } else {
        return _insert_element_child(node->right, point, size_props, element,
                                     split_case + 1);
      }
    } else {
      if (node->left == NULL) {
        node->left = (Node *)malloc(sizeof(Node));
        void *new_element = malloc(size_props);
        memcpy(new_element, element, size_props);
        *(node->left) = (Node){
            .point = point,
            .Obj = element,
            .right = NULL,
            .left = NULL,
            .father = node,
        };
        return true;
      } else {
        return _insert_element_child(node->left, point, size_props, element,
                                     split_case + 1);
      }
    }
  } else {
    if (node->point.x < point.x) {
      if (node->right == NULL) {
        node->right = (Node *)malloc(sizeof(Node));
        void *new_element = malloc(size_props);
        memcpy(new_element, element, size_props);
        *(node->right) = (Node){
            .point = point,
            .Obj = element,
            .right = NULL,
            .left = NULL,
            .father = node,
        };
        return true;
      } else {
        return _insert_element_child(node->right, point, size_props, element,
                                     split_case + 1);
      }
    } else {
      if (node->left == NULL) {
        node->left = (Node *)malloc(sizeof(Node));
        void *new_element = malloc(size_props);
        memcpy(new_element, element, size_props);
        *(node->left) = (Node){
            .point = point,
            .Obj = element,
            .right = NULL,
            .left = NULL,
            .father = node,
        };
        return true;
      } else {
        return _insert_element_child(node->left, point, size_props, element,
                                     split_case + 1);
      }
    }
  }
  return false;
}

void *get_element(const kdTree *tree, const Point *point,
                  const size_t size_props) {
  if (tree->root != NULL) {
    return _get_element_child(tree->root, point, size_props, 1);
  }
  return NULL;
}

bool _same_point(const Point *point1, const Point *point2) {
  if (point1->x == point2->y && point1->y == point2->y)
    return true;

  return false;
}

void *_get_element_child(const Node *node, const Point *point,
                         const size_t size_props, const int split_case) {
  if (_same_point(&node->point, point)) {
    // void* retorno = malloc(size_props);
    // memcpy(retorno, node->Obj, size_props);
    // return retorno;
    return node->Obj;
  } else {
    if (split_case % 2 == 0) {
      if (node->point.x < point->x) {
        if (node->right != NULL) {
          return _get_element_child(node->right, point, size_props,
                                    split_case + 1);
        } else {
          return NULL;
        }
      } else {
        if (node->left != NULL) {
          return _get_element_child(node->left, point, size_props,
                                    split_case + 1);
        } else {
          return NULL;
        }
      }
    } else {
      if (node->point.y < point->y) {
        if (node->right != NULL) {
          return _get_element_child(node->right, point, size_props,
                                    split_case + 1);
        } else {
          return NULL;
        }
      } else {
        if (node->left != NULL) {
          return _get_element_child(node->left, point, size_props,
                                    split_case + 1);
        } else {
          return NULL;
        }
      }
    }
  }
}

Point _random_point() {
  return (Point){
      .x = (double)rand(),
      .y = (double)rand(),
  };
}

Point _clone_point(const Point *point) {
  if (point != NULL) {
    return (Point){
        .x = point->x,
        .y = point->y,
    };
  }
  return (Point){
      .x = 0.0,
      .y = 0.0,
  };
}

void print_tree(kdTree *tree) {
  if (tree->root != NULL) {
    _print_node(tree->root, 0);
  }
  return;
}

void _print_node(Node *node, size_t spaces) {

  if (node->right != NULL) {
    _print_node(node->right, spaces + 1);
  }
  for (int i = 0; i < spaces; i++) {
    printf(" ");
  }
  printf("x: %lf, y: %lf\n", node->point.x, node->point.y);
  if (node->left != NULL) {
    _print_node(node->left, spaces + 1);
  }
}
