#ifndef uint16_t, uint8_t, uint32_t
#include "types.h"
#endif

#ifndef ___GDT_H
#define ___GDT_H

class GlobalDescriptorTable{
    public: 
        class SegmentSelector{
            private:
                uint16_t limit_lo;
                uint16_t base_lo;
                uint8_t base_hi;
                uint8_t flags_limit_hi;
                uint8_t base_vhi;
            public:
                SegmentSelector(uint32_t base, uint32_t limit, uint8_t type);
                uint32_t Base();
                uint32_t Limit();
        } __attribute__((packed));

        SegmentSelector nullSegmentSelector;
        SegmentSelector unusedSegmentSelector;
        SegmentSelector codeSegmentSelector;
        SegmentSelector dataSegmentSelector;

        GlobalDescriptorTable();
        ~GlobalDescriptorTable();
        uint16_t CodeSegmentSelector();
        uint16_t DataSegmentSelector();
};

#endif