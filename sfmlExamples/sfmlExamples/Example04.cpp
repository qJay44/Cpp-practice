//#include <iostream>
//#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>
//#include <SFML/System.hpp>
//
//using namespace sf;
//
//int main()
//{
//    RenderWindow window(VideoMode(640, 400), "SFML works!");
//    window.setFramerateLimit(90);
//
//    CircleShape triangle;
//    triangle.setRadius(50.f);
//    triangle.setPointCount(3);
//    triangle.setFillColor(Color::Red);
//    triangle.setOutlineThickness(5.f);
//    triangle.setOutlineColor(Color::Blue);
//
//    Vertex line[] = { Vertex(Vector2f(100.f, 400.f)), Vertex(Vector2f(50.f, 100.f)) };
//
//    ConvexShape convex;
//    convex.setPosition(Vector2f(400.f, 50.f));
//
//    convex.setPointCount(5);
//
//    convex.setPoint(0, Vector2f(0, 0));
//    convex.setPoint(1, Vector2f(150, 10));
//    convex.setPoint(2, Vector2f(120, 90));
//    convex.setPoint(3, Vector2f(30, 100));
//    convex.setPoint(4, Vector2f(0, 50));
//
//    while (window.isOpen())
//    {
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//
//        window.draw(triangle);
//        window.draw(line, 2, Lines);
//        window.draw(convex);
//
//        window.display();
//    }
//
//    return 0;
//}
