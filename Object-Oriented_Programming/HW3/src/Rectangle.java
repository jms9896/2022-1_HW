/*
 * Q: Write Rectangle class that implements the following features:
 *
 * 1. Make RectangleRunner.java run with Rectangle class that you design
 *      in Rectangle.java
 *      a. First of all, take a look at output_RectangleRunner.txt and
 *          plan to make RectangleRunner.class generate the desired output
 *      b. No need to modify RectangleRunner.java. Only write code lines
 *          in Rectangle.java
 *      c. Start by modifying the template in this file (Rectangle.java)
 * 2. In particular, design Rectangle class applying the object design technique
 *      of ADT (Abstract Data Type):
 *      a. instance variables declared as private
 *      b. constructors with width and height variables as initial input parameters
 *      c. methods: calculateArea(), print(), resize()
 *      d. setters and getters for the instance variables
 */

public class Rectangle
{

    /* instance variables go here (width and height) */
    private int width;
    private int height;
    
    /* Constructors */

    /*public Rectangle(){
        this(width:0, height:0);
    }*/
    public Rectangle(int w, int h) {
        setRectangle(w,h);
    }

    public void setRectangle(int w, int h){
        width = w;
        height = h;
    }

    /* Methods: calculateArea(), print(), resize() */

    public int calculateArea() {
        return width*height;
    }

    public void print() {
        System.out.println(width + " * " + height);
        for (int i = 1; i <= height; i++){
            for (int j = 1; j <= width; j++){
                System.out.print("*");
            }
            System.out.println();
        }
        //System.out.println();
    }

    public void resize(int w, int h) {
        width = w;
        height = h;
    }

    public void setHeight(int h) {
        height = h;
    }

    /* Setters and getters */
    public int getWidth(){
        return width;
    }
    public int getHeight(){
        return height;
    }
/*    public void setWidth(int width){
        this.width = width;
    }
    public void setHeight(){

    }*/
}
