public class RectangleRunner
{
    public static void main(String[] args)
    {
        /* Rectangle(width, height) */
        Rectangle smallRectangle = new Rectangle(3, 4);
        Rectangle bigRectangle = new Rectangle(20, 10);

        System.out.println("### Rectangular areas");
        System.out.println("A small one: " + smallRectangle.calculateArea());
        System.out.println("A big one: " + bigRectangle.calculateArea());

        System.out.println();

        System.out.println("### Shapes");
        smallRectangle.print();     // prints out width & height data and shapes with stars
        System.out.println();
        bigRectangle.print();

        System.out.println();

        System.out.println("### Resizing the small one:");
        smallRectangle.resize(5, 3);        /* 5 for width, 3 for height */
        smallRectangle.print();

        System.out.println();

        System.out.println("### Changing the height of the big one using setter:");
        bigRectangle.setHeight(5);
        bigRectangle.print();
    }
}
