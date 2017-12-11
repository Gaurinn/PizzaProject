#ifndef EXTRAFOODSERVICE_H
#define EXTRAFOODSERVICE_H

#include "ExtraFoodRepository.h"


class ExtraFoodService
{
    public:
        ExtraFoodService();
        virtual ~ExtraFoodService();
    protected:
    private:

        vector<ExtraFood> retrieveAllExtraFood();


        ExtraFoodRepository extrafoodrepo;
};

#endif // EXTRAFOODSERVICE_H
