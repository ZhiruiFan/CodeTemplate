#include <iostream>
#include <initializer_list>
class Mat
{
    public:
        int NumMat;
        double* E;
        double* mu;
    public:
        void AssignMat(const int& NumMat, std::initializer_list<double> Pro, const double& mu);
        void print();
};
void Mat::AssignMat(const int& NumMat, std::initializer_list<double> pro, const double& mu)
{
    this->NumMat = NumMat;
    this->E = new double[NumMat];
    this->mu = new double[NumMat];
    if (pro.size() !=  NumMat) exit(0);
    int i = 0;
    for (auto beg = pro.begin(); beg != pro.end(); ++beg)
    {
        this->E[i] = *beg; this->mu[i] = mu;
        ++i;
    }
}
void Mat::print()
{
    for (int i = 0; i < this->NumMat; ++i){
        printf("Material-%d: E = %.3f, mu = %.3f\n", i, this->E[i], this->mu[i]);
    }
}
int main()
{
    Mat* mat = new Mat();
    mat->AssignMat(2, {1.0, 2.0}, 0.3);
    mat->print();
    return 0;
}
