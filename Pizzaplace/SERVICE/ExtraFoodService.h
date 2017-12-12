#ifndef EXTRAFOODSERVICE_H
#define EXTRAFOODSERVICE_H

#include "ExtraFoodRepository.h"


class ExtraFoodService
{
    public:
        ExtraFoodService();


        vector<ExtraFood> retrieveAllExtraFoodService();
        void storeExtraFoodService(const ExtraFood& extrafood);


        virtual ~ExtraFoodService();
    protected:
    private:



        ExtraFoodRepository extrafoodrepo;
};

#endif // EXTRAFOODSERVICE_H
