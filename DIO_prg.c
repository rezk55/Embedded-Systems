
/*****************************************************************************************/
/** Author      : Rezk Abdelnabi Abdelmonem  *********************************************/
/** Description : Program file               *********************************************/
/** Date        : 8/11/2019                  *********************************************/
/** Virsion     : 1.0                        *********************************************/
/*****************************************************************************************/

/*             Liberary Directives                */
#include "Std_types.h"
#include "Bit_math.h"

/*             DIO Directives                     */
#include "DIO_int.h"
#include "DIO_cfg.h"
#include "DIO_prv.h" 


/**************************************************/
/*             DIO Implementation                 */
/**************************************************/


/**************************************************/
/* Description : Initialize PINS Directions       */

void DIO_voidInit(void)
{
	DDRA = DIO_u8_PORTA_DIRECTIONS;
	DDRB = DIO_u8_PORTB_DIRECTIONS;
	DDRC = DIO_u8_PORTC_DIRECTIONS;
	DDRD = DIO_u8_PORTD_DIRECTIONS;
   	
}

/********** End Initialize PINS Directions ********/



/**************************************************/
/* Description : This Function Set The Pin        */
/*               Value to either High or Low      */

void DIO_voidSetPinValue(u8 Copy_u8PinNumber , u8 Copy_u8PinValue)
{
	
	/*   FIND PORT A PINS                          */
	if (Copy_u8PinNumber >= DIO_u8_PORTA_START && Copy_u8PinNumber <= DIO_u8_PORTA_END)
	{
		/*  Check value passed to fuction HIGH    */

		if (Copy_u8PinValue == DIO_u8_HIGH )
		{
			/*   MAKE pin numer Copy_u8PinNumber HIGH */

			SET_BIT(PORTA , Copy_u8PinNumber);
		}
		/*  Check value passed to fuction LOW    */
		else 
		{
			/*   MAKE pin numer Copy_u8PinNumber LOW */

			CLEAR_BIT(PORTA, Copy_u8PinNumber);
		}

	}
	/*   FIND PORT B PINS                          */
	else if (Copy_u8PinNumber >= DIO_u8_PORTB_START && Copy_u8PinNumber <= DIO_u8_PORTB_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - DIO_u8_PORTA_SIZE ; 

		if (Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT (PORTB , Copy_u8PinNumber);
		}
		else 
		{
			CLEAR_BIT(PORTB , Copy_u8PinNumber);
		}

	}
	/*   FIND PORT C PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTC_START &&  Copy_u8PinNumber <= DIO_u8_PORTC_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - ( DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE ) ; 

		if (Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT (PORTC , Copy_u8PinNumber);
		}
		else 
		{
			CLEAR_BIT(PORTC , Copy_u8PinNumber);
		}	
	}
	/*   FIND PORT D PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTD_START &&  Copy_u8PinNumber <= DIO_u8_PORTD_END)
	{

		Copy_u8PinNumber = Copy_u8PinNumber - ( DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE ) ; 

		if (Copy_u8PinValue == DIO_u8_HIGH )
		{
			SET_BIT (PORTD , Copy_u8PinNumber);
		}
		else 
		{
			CLEAR_BIT(PORTD , Copy_u8PinNumber);
		}

	}
}
/*******************End Function Set The Pin *******/


/**************************************************/
/* Description : This Function Get The Pin         */
/*               Value to either High or Low       */

u8 DIO_u8GETPinValue(u8 Copy_u8PinNumber )
{
	u8 LOC_u8ReturnedPinValue;
	if (Copy_u8PinNumber >= DIO_u8_PORTA_START && Copy_u8PinNumber <= DIO_u8_PORTA_END)
	{
		LOC_u8ReturnedPinValue = GET_BIT(PINA,Copy_u8PinNumber);
	}
	/*   FIND PORT B PINS                          */
	else if (Copy_u8PinNumber >= DIO_u8_PORTB_START && Copy_u8PinNumber <= DIO_u8_PORTB_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - (DIO_u8_PORTA_SIZE);
		LOC_u8ReturnedPinValue = GET_BIT(PINB , Copy_u8PinNumber);

	}
	/*   FIND PORT C PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTC_START &&  Copy_u8PinNumber <= DIO_u8_PORTC_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - (DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE);
		LOC_u8ReturnedPinValue = GET_BIT(PINC , Copy_u8PinNumber);

	}
	/*   FIND PORT D PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTD_START &&  Copy_u8PinNumber <= DIO_u8_PORTD_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - (DIO_u8_PORTA_SIZE +  DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE);
		LOC_u8ReturnedPinValue = GET_BIT(PIND , Copy_u8PinNumber);

	}
	return LOC_u8ReturnedPinValue ;
	
}
/************* End Function Get The Pin value ******/



/***************************************************/
/* Description : This Function Set The Pin         */
/*               Direction In Run Time             */

void DIO_voidSetPinDirection (u8 Copy_u8PinNumber , u8 Copy_u8PinNumberDir )
{
	/*   FIND PORT A PINS                          */
	if (Copy_u8PinNumber >= DIO_u8_PORTA_START && Copy_u8PinNumber <= DIO_u8_PORTA_END)
	{
		/*  Check value passed to function HIGH    */

		if (Copy_u8PinNumberDir == DIO_u8_OUTPUT )
		{
			/*   MAKE pin number Copy_u8PinNumber HIGH */

			SET_BIT(DDRA , Copy_u8PinNumber);
		}
		/*  Check value passed to function LOW    */
		else
		{
			/*   MAKE pin number Copy_u8PinNumber LOW */

			CLEAR_BIT(DDRA, Copy_u8PinNumber);
		}

	}
	/*   FIND PORT B PINS                          */
	else if (Copy_u8PinNumber >= DIO_u8_PORTB_START && Copy_u8PinNumber <= DIO_u8_PORTB_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - DIO_u8_PORTA_SIZE ;

		if (Copy_u8PinNumberDir == DIO_u8_OUTPUT )
		{
			/*   MAKE pin number Copy_u8PinNumber HIGH */

			SET_BIT(DDRB , Copy_u8PinNumber);
		}
		/*  Check value passed to function LOW    */
		else
		{
			/*   MAKE pin number Copy_u8PinNumber LOW */

			CLEAR_BIT(DDRB, Copy_u8PinNumber);
		}

	}
	/*   FIND PORT C PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTC_START &&  Copy_u8PinNumber <= DIO_u8_PORTC_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - ( DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE ) ;

		if (Copy_u8PinNumberDir == DIO_u8_OUTPUT )
		{
			/*   MAKE pin number Copy_u8PinNumber HIGH */

			SET_BIT(DDRC , Copy_u8PinNumber);
		}
		/*  Check value passed to function LOW    */
		else
		{
			/*   MAKE pin number Copy_u8PinNumber LOW */

			CLEAR_BIT(DDRC, Copy_u8PinNumber);
		}
	}
	/*   FIND PORT D PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTD_START &&  Copy_u8PinNumber <= DIO_u8_PORTD_END)
	{

		Copy_u8PinNumber = Copy_u8PinNumber - ( DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE ) ;

		if (Copy_u8PinNumberDir == DIO_u8_OUTPUT )
		{
			/*   MAKE pin number Copy_u8PinNumber HIGH */

			SET_BIT(DDRD , Copy_u8PinNumber);
		}
		/*  Check value passed to function LOW    */
		else
		{
			/*   MAKE pin number Copy_u8PinNumber LOW */

			CLEAR_BIT(DDRD, Copy_u8PinNumber);
		}
	}	
}
/****************** End Function Set The Pin Direction ***************/



/**************************************************/
/*Description : This Function Toggle The Pin Value*/

void DIO_voidTogglePin (u8 Copy_u8PinNumber  )
{
	
	/*   FIND PORT A PINS                          */
	if (Copy_u8PinNumber >= DIO_u8_PORTA_START && Copy_u8PinNumber <= DIO_u8_PORTA_END)
	{
		TOGGLE_BIT(PORTA ,Copy_u8PinNumber);

	}
	/*   FIND PORT B PINS                          */
	else if (Copy_u8PinNumber >= DIO_u8_PORTB_START && Copy_u8PinNumber <= DIO_u8_PORTB_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - DIO_u8_PORTA_SIZE ;
		TOGGLE_BIT(PORTB ,Copy_u8PinNumber);


	}
	/*   FIND PORT C PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTC_START &&  Copy_u8PinNumber <= DIO_u8_PORTC_END)
	{
		Copy_u8PinNumber = Copy_u8PinNumber - ( DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE ) ;
		TOGGLE_BIT(PORTC ,Copy_u8PinNumber);

	}
	/*   FIND PORT D PINS                          */
	else if(Copy_u8PinNumber >= DIO_u8_PORTD_START &&  Copy_u8PinNumber <= DIO_u8_PORTD_END)
	{

		Copy_u8PinNumber = Copy_u8PinNumber - ( DIO_u8_PORTA_SIZE + DIO_u8_PORTB_SIZE + DIO_u8_PORTC_SIZE ) ;

		TOGGLE_BIT(PORTD ,Copy_u8PinNumber);

	}
	
}
/*******************End Function Toggle ***************/
































