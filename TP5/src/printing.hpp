#ifndef _PRINTING_HPP_
#define _PRINTING_HPP_

#include "vertex.hpp"
#include "edge.hpp"

#include <functional>
#include <vector>

std::function<void(Vertex& root, Edge& branch)> dotPrint();
std::function<void(Vertex& root, Edge& branch)> dotPrintColored(std::vector<int> revPath);

#endif
