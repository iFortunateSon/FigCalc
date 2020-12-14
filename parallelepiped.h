#ifndef PARALLELEPIPED_H
#define PARALLELEPIPED_H
#include "volumfigure.h"

class parallelepiped : public VolumeFigure
{
    /*
     * a, b, c - стороны
    */
    public:
        parallelepiped(const float a, const float b,const float c);
        parallelepiped(const parallelepiped &oval);


        void setSideA(const float size);
        void setSideB(const float size);
        void setSideC(const float size);

        float getSideA() const;
        float getSideB() const;
        float getSideC() const;

        float getVolume() const override;
        float getSquare() const override;
        QString getInfoAsStr() const override;
        float getDiagonal() const;

    private:

    };


#endif // PARALLELEPIPED_H
