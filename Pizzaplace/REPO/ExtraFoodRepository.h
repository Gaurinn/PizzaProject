#ifndef EXTRAFOODREPOSITORY_H
#define EXTRAFOODREPOSITORY_H
#include "../MODEL/ExtraFood.h"
#include <vector>
using namespace std;

class ExtraFoodRepository
{
    public:
        ExtraFoodRepository();
        virtual ~ExtraFoodRepository();

        void storeExtraFood(const ExtraFood& extrafood);
        ExtraFood retrieveExtraFood();

        vector<ExtraFood> retrieveAllExtraFood();
    protected:
    private:
};

#endif // EXTRAFOODREPOSITORY_H
