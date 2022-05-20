#ifndef GPIO_REGISTER_H
#define GPIO_REGISTER_H

#define GPIOA_REG(OFFSET) ((unsigned int *)(0x40020000 + OFFSET))
#define GPIOB_REG(OFFSET) ((unsigned int *)(0x40020400 + OFFSET))
#define RCC_AHB1ENR       ((unsigned int *)0x40023830)


#define MODER_OFFSET    0x00
#define OTYPER_OFFSET   0x04
#define OSPEEDR_OFFSET  0x08
#define PUPDR_OFFSET    0x0C
#define IDR_OFFSET      0x10
#define ODR_OFFSET      0x14
#define BSRR_OFFSET     0x18
#define LCKR_OFFSET     0x1C
#define AFRL_OFFSET     0x20
#define AFRH_OFFSET     0x24

#define CLOCK           0 
#define MODER           1
#define OTYPER          2
#define OSPEEDR         3
#define PUPDR           4
#define IDR             5
#define ODR             6
#define BSRR            7
#define LCKR            8
#define AFRL            9
#define AFRH            10

unsigned int *LookUp[2][11] = {
    {
        RCC_AHB1ENR,
        GPIOA_REG(MODER_OFFSET),
        GPIOA_REG(OTYPER_OFFSET),
        GPIOA_REG(OSPEEDR_OFFSET),
        GPIOA_REG(PUPDR_OFFSET),
        GPIOA_REG(IDR_OFFSET),
        GPIOA_REG(ODR_OFFSET),
        GPIOA_REG(BSRR_OFFSET),
        GPIOA_REG(LCKR_OFFSET),
        GPIOA_REG(AFRL_OFFSET),
        GPIOA_REG(AFRH_OFFSET),
    },
    {
        RCC_AHB1ENR,
        GPIOB_REG(MODER_OFFSET),
        GPIOB_REG(OTYPER_OFFSET),
        GPIOB_REG(OSPEEDR_OFFSET),
        GPIOB_REG(PUPDR_OFFSET),
        GPIOB_REG(IDR_OFFSET),
        GPIOB_REG(ODR_OFFSET),
        GPIOB_REG(BSRR_OFFSET),
        GPIOB_REG(LCKR_OFFSET),
        GPIOB_REG(AFRL_OFFSET),
        GPIOB_REG(AFRH_OFFSET),
    }};

#endif
