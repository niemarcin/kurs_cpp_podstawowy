#pragma once

int NWD(int lhs, int rhs) {
   if (rhs != 0){
        return NWD (rhs, lhs%rhs);
   }
    return std::abs(lhs); 
}

int NWW(int lhs, int rhs) {
    if (lhs==0 || rhs==0){
        return 0;
    }
    return std::abs(lhs * rhs) / NWD(lhs,rhs);
}
