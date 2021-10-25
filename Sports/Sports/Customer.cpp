#include "Customer.h"

EquipmentWarehouse Customer::storage = {};

void Customer::SortEquipmentsByBrand()
{
    sort(storage.GetIteratorToBegin(), storage.GetIteratorToEnd(), BrandLessThanOther());
}

void Customer::SortEquipmentsBykind()
{
    sort(storage.GetIteratorToBegin(), storage.GetIteratorToEnd(), kindLessThanOther());
}

string Customer::GetMostPopularEquipmentBrand()
{
    int res_idx = 0;
    int count = 1;

    for (int i = 1; i < storage.GetSize(); i++)
    {
        if (storage.GetEquipmentBrand(i) == storage.GetEquipmentBrand(res_idx))
            count++;
        else
            count--;

        if (count == 0)
        {
            res_idx = i;
            count = 1;
        }
    }

    return storage.GetEquipmentBrand(res_idx);
}

string Customer::GetMostPopularEquipmentkind()
{
    int res_idx = 0;
    int count = 1;

    for (int i = 1; i < storage.GetSize(); i++)
    {
        if (storage.GetEquipmentkind(i) == storage.GetEquipmentkind(res_idx))
            count++;
        else
            count--;

        if (count == 0)
        {
            res_idx = i;
            count = 1;
        }
    }

    return storage.GetEquipmentkind(res_idx);
}