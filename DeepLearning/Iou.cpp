#include <bits/stdc++.h>
using namespace std;

struct Rect {
    float x; // left-top x
    float y; // left-top y
    float w;
    float h;
};


float calIoU(Rect &rect1, Rect &rect2) {
    float x1 = max(rect1.x, rect2.x);
    float y1 = max(rect1.y, rect2.y);
    float x2 = min(rect1.x + rect1.w, rect2.x + rect2.w);
    float y2 = min(rect1.y + rect1.h, rect2.y + rect2.h);

    float S1 = rect1.w * rect1.h;
    float S2 = rect2.w * rect2.h;
    float S = ((x2 - x1) > 0 ? (x2 - x1) : 0) * ((y2 - y1) > 0 ? (y2 - y1) : 0);
    float iou = S / (S1 + S2 - S);
    return iou;
}
