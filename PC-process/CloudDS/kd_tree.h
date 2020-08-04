class point {
public: 
    point() {
        x = 0;
        y = 0;
    };
    point(point &p) {
        x = p.x;
        y = p.y;
    }
    ~point() {};
    double x;
    double y;
};
  
struct KDnode {
    point dom_elt;
    int split;
    int partDimention;
    struct KDnode * left;
    struct KDnode * right;
};

bool cmp1(point a, point b) {
    return a.x < b.x;
}

bool cmp2(point a, point b) {
    return a.y < b.y;
}

bool equal(point a, point b) {
    if (a.x == b.x && a.y == b.y)
    {
        return true;
    }
    else{
        return false;
    }
}