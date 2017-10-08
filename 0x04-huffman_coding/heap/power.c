/**
 * power - calculates the exponential value of a number.
 * @num: A number.
 * @exponent: An exponent.
 *
 * Return: Value of num to the power of exponent.
 */
int power(int num, int exponent)
{
        int value;

        value = num;
        while (exponent)
        {
                value *= num;
                exponent--;
        }

        return (value);
}
