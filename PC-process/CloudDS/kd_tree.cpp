#include <iostream>
#include <algorithm>
#include <stack>
#include <math.h>
#include "kd_tree.h"
using namespace std;

/*function of this program: build a 2d tree using the input training data  
 the input is exm_set which contains a list of tuples (x,y)  
 the output is a 2d tree pointer*/

void ChooseSplit(point exm_set[], int size, int &split, point &SplitChoice){
    /*compute the variance on every dimension. Set split as the dismension that have the biggest
     variance. Then choose the instance which is the median on this split dimension.*/
    // 计算每个维度的 方差，选择方差最大的维度做分解，选改维度的 中位数 

    /*compute variance on the x,y dimension. DX=EX^2-(EX)^2*/
    double tmp1, tmp2;
    tmp1 = tmp2 = 0;
    for (int i = 0; i < size; ++i)
    {
        tmp1 += 1.0 / (double)size * exm_set[i].x * exm_set[i].x;
        tmp2 += 1.0 / (double)size * exm_set[i].x;
    }
    // 维度 1 的方差
    double v1 = tmp1 - tmp2 * tmp2;  //compute variance on the x dimension

    tmp1 = tmp2 = 0;
    for (int i = 0; i < size; ++i)
    {
        tmp1 += 1.0 / (double)size * exm_set[i].y * exm_set[i].y;
        tmp2 += 1.0 / (double)size * exm_set[i].y;
    }
    // 维度 2 的方差
    double v2 = tmp1 - tmp2 * tmp2;  //compute variance on the y dimension

    split = v1 > v2 ? 0:1; //set the split dimension

    if (split == 0)
    {
        sort(exm_set,exm_set + size, cmp1);
    }
    else{
        sort(exm_set,exm_set + size, cmp2);
    }

    //set the split point value
    SplitChoice.x = exm_set[size / 2].x;
    SplitChoice.y = exm_set[size / 2].y;

}

KDnode* build_kdtree(point exm_set[], int size, KDnode* T){
    //call function ChooseSplit to choose the split dimension and split point
    if (size == 0){
        return NULL;
    }
    else{
        int split;
        point dom_elt;
        ChooseSplit(exm_set, size, split, dom_elt);
        point exm_set_right [100];
        point exm_set_left [100];
        int sizeleft ,sizeright;
        sizeleft = sizeright = 0;

        if (split == 0)
        {
            for (int i = 0; i < size; ++i)
            {

                if (!equal(exm_set[i],dom_elt) && exm_set[i].x <= dom_elt.x)
                {
                    exm_set_left[sizeleft].x = exm_set[i].x;
                    exm_set_left[sizeleft].y = exm_set[i].y;
                    sizeleft++;
                }
                else if (!equal(exm_set[i],dom_elt) && exm_set[i].x > dom_elt.x)
                {
                    exm_set_right[sizeright].x = exm_set[i].x;
                    exm_set_right[sizeright].y = exm_set[i].y;
                    sizeright++;
                }
            }
        }
        else{
            for (int i = 0; i < size; ++i)
            {

                if (!equal(exm_set[i],dom_elt) && exm_set[i].y <= dom_elt.y)
                {
                    exm_set_left[sizeleft].x = exm_set[i].x;
                    exm_set_left[sizeleft].y = exm_set[i].y;
                    sizeleft++;
                }
                else if (!equal(exm_set[i],dom_elt) && exm_set[i].y > dom_elt.y)
                {
                    exm_set_right[sizeright].x = exm_set[i].x;
                    exm_set_right[sizeright].y = exm_set[i].y;
                    sizeright++;
                }
            }
        }
        T = new KDnode;
        T->dom_elt.x = dom_elt.x;
        T->dom_elt.y = dom_elt.y;
        T->split = split;
        T->left = build_kdtree(exm_set_left, sizeleft, T->left);
        T->right = build_kdtree(exm_set_right, sizeright, T->right);
        return T;
    }
}

double Distance(point a, point b){
    double tmp = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    return sqrt(tmp);
}


void searchNearest(KDnode * Kd, point target, point &nearestpoint, double & distance){

    //1. 如果Kd是空的，则设dist为无穷大返回

    //2. 向下搜索直到叶子结点

    stack<KDnode*> search_path;
    KDnode* pSearch = Kd;
    point nearest;
    double dist;

    while(pSearch != NULL)
    {
        //pSearch加入到search_path中;
        search_path.push(pSearch);

        if (pSearch->split == 0)
        {
            if(target.x <= pSearch->dom_elt.x) /* 如果小于就进入左子树 */    
            {
                pSearch = pSearch->left;
            }
            else
            {
                pSearch = pSearch->right;
            }
        }
        else{
            if(target.y <= pSearch->dom_elt.y) /* 如果小于就进入左子树 */
            {
                pSearch = pSearch->left;
            }
            else
            {
                pSearch = pSearch->right;
            }
        }
    }
    //取出search_path最后一个赋给nearest
    nearest.x = search_path.top()->dom_elt.x;
    nearest.y = search_path.top()->dom_elt.y;
    search_path.pop();


    dist = Distance(nearest, target);
    //3. 回溯搜索路径

    KDnode* pBack;

    while(search_path.size() != 0)
    {
        //取出search_path最后一个结点赋给pBack
        pBack = search_path.top();
        search_path.pop();

        if(pBack->left == NULL && pBack->right == NULL) /* 如果pBack为叶子结点 */
        {

            if( Distance(nearest, target) > Distance(pBack->dom_elt, target) )
            {
                nearest = pBack->dom_elt;
                dist = Distance(pBack->dom_elt, target);
            }
        }
        else
        {
            int s = pBack->split;
            if (s == 0)
            {
                if( fabs(pBack->dom_elt.x - target.x) < dist) /* 如果以target为中心的圆（球或超球），半径为dist的圆与分割超平面相交， 那么就要跳到另一边的子空间去搜索 */
                {
                    if( Distance(nearest, target) > Distance(pBack->dom_elt, target) )
                    {
                        nearest = pBack->dom_elt;
                        dist = Distance(pBack->dom_elt, target);
                    }
                    if(target.x <= pBack->dom_elt.x) /* 如果target位于pBack的左子空间，那么就要跳到右子空间去搜索 */
                        pSearch = pBack->right;
                    else
                        pSearch = pBack->left; /* 如果target位于pBack的右子空间，那么就要跳到左子空间去搜索 */
                    if(pSearch != NULL)
                        //pSearch加入到search_path中
                        search_path.push(pSearch);
                }
            }
            else {
                if( fabs(pBack->dom_elt.y - target.y) < dist) /* 如果以target为中心的圆（球或超球），半径为dist的圆与分割超平面相交， 那么就要跳到另一边的子空间去搜索 */
                {
                    if( Distance(nearest, target) > Distance(pBack->dom_elt, target) )
                    {
                        nearest = pBack->dom_elt;
                        dist = Distance(pBack->dom_elt, target);
                    }
                    if(target.y <= pBack->dom_elt.y) /* 如果target位于pBack的左子空间，那么就要跳到右子空间去搜索 */
                        pSearch = pBack->right;
                    else
                        pSearch = pBack->left; /* 如果target位于pBack的右子空间，那么就要跳到左子空间去搜索 */
                    if(pSearch != NULL)
                       // pSearch加入到search_path中
                        search_path.push(pSearch);
                }
            }
        }
    }
    nearestpoint.x = nearest.x;
    nearestpoint.y = nearest.y;
    distance = dist;
}    
    
int main() {    
    point exm_set[100]; //assume the max training set size is 100
    double x,y;
    int id = 0;
    cout<<"Please input the training point in the form x y. One instance per line. Enter -1 -1 to stop."<<endl;
    while (cin>>x>>y){
        if (x == -1)
        {
            break;
        }
        else{
            exm_set[id].x = x;
            exm_set[id].y = y;
            id++;
        }
    }
    struct KDnode * root = NULL;
    root = build_kdtree(exm_set, id, root);

    point nearestpoint;
    double distance;
    point target;
    cout <<"Enter search point"<<endl;
    while (cin>>target.x>>target.y)
    {
        searchNearest(root, target, nearestpoint, distance);
        cout<<"The nearest distance is "<<distance<<",and the nearest point is "<<nearestpoint.x<<","<<nearestpoint.y<<endl;
        cout <<"Enter search point"<<endl;
    }
}