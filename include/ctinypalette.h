#ifndef CTINYPALETTE_H_
#define CTINYPALETTE_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdlib.h>

typedef struct CTPRGB16
{
    uint16_t red;
    uint16_t green;
    uint16_t blue;
} CTPRGB16;

inline CTPRGB16 *ctp_rgb_16_new(const uint16_t red, const uint16_t green, const uint16_t blue)
{
    CTPRGB16 *self = (CTPRGB16 *)malloc(sizeof(CTPRGB16));
    if (self == NULL)
    {
        return NULL;
    }

    self->red = red;
    self->green = green;
    self->blue = blue;

    return self;
}

inline void ctp_rgb_16_delete(CTPRGB16 *self)
{
    free(self);
}

typedef struct CTPHSV16
{
    /**
     * [0, 360) deg mapped to [0, UINT16_MAX].
     * hue=UINT16_MAX does not imply hue=0, but means the closest representable value to 360deg.
     */
    uint16_t hue;
    /**
     * [0, 1] mapped to [0, UINT16_MAX].
     */
    uint16_t saturation;
    /**
     * [0, 1] mapped to [0, UINT16_MAX].
     */
    uint16_t value;
} CTPHSV16;

inline CTPHSV16 *ctp_hsv_16_new(const uint16_t hue, const uint16_t saturation, const uint16_t value)
{
    CTPHSV16 *self = (CTPHSV16 *)malloc(sizeof(CTPHSV16));
    if (self == NULL)
    {
        return NULL;
    }

    self->hue = hue;
    self->saturation = saturation;
    self->value = value;

    return self;
}

inline void ctp_hsv_16_delete(CTPHSV16 *self)
{
    free(self);
}

CTPRGB16 *ctp_hsv_16_to_rgb_16(CTPHSV16 *self);

#ifdef __cplusplus
}
#endif

#endif
