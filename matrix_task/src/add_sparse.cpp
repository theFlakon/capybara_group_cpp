#include "add_sparse.h"
#include "matrix.h"
#include <cstddef>
#include <cstdlib>
#include <cmath>

ComprMatrix addSparse(const ComprMatrix& lhs, const ComprMatrix& rhs) {
    ComprMatrix result;
    size_t lptr = 0;
    size_t rptr = 0;
    while(lptr < lhs.size() && rptr < rhs.size()) {
        if(lhs[lptr].row < rhs[rptr].row ||
                (lhs[lptr].row == rhs[rptr].row && lhs[lptr].col < rhs[rptr].col)) {
            result.push_back(lhs[lptr]);
            lptr++;
        }
        else if(rhs[rptr].row < lhs[lptr].row ||
                (rhs[rptr].row == lhs[lptr].row && rhs[rptr].col < lhs[lptr].col)) {
            result.push_back(rhs[rptr]);
            rptr++;
        }
        else {
            Element el = rhs[rptr];
            el.val += lhs[lptr].val;
            if(std::fabs(el.val) > 1e-9) {
                result.push_back(el);
            }
            rptr++;
            lptr++;
        }
    }
    while(lptr < lhs.size()) result.push_back(lhs[lptr++]);
    while(rptr < rhs.size()) result.push_back(rhs[rptr++]);
    return result;
}