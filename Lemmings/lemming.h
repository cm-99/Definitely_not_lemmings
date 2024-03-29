#ifndef LEMMING_H
#define LEMMING_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Lemming : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Lemming();
    virtual ~Lemming() = default;
    virtual void move();

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /**
     * Swaps lemming's instance calling this method with instance passed as @param:lemming.
     * Swaping means here copying shared attributes and placing @param:lemming at position of calling instance.
     * @param lemming
     */
    void change_class(Lemming* lemming);
    /**
     * Swamps lemming's instance calling this method with new instance of class JoblessLemming.
     */
    void fire_lemming();

    /**
     * Checks if calling instance's position is out of scene based on dimensions of Map and lemming's bounding rectangle.
     * @return - returns true if lemming is out of scene. Otherwise returns false.
     */
    bool check_for_lemming_out_of_scene();

    /**
     * Chceks if lemming is moving in the direction of the @param:obstacle.
     * It's based on positions x value of calling lemming and obstacle and lemming's speed vector.
     * @return - returns true if lemming is moving in the direction of the obstacle
     */
    bool check_for_lemming_moving_in_direction_of_the_obstacle(QGraphicsItem *obstacle);

    void resolve_collision_with_exit(); 
    bool check_for_same_sign(int num1, int num2);
    void safely_delete_lemming(bool lemming_was_saved);

    int x_axis_speed = 2;
    int y_axis_speed = 0;
    const int default_x_axis_speed = 2;
    const int default_y_axis_speed = 2;
    int largest_obstacle_height_prevalence = -1;
    bool accept_class_change = false;
    bool lemming_is_waiting_for_deletion = false;
    int fall_height_counter = 0;
    int death_fall_height = 320;

private:
    int lower_lemmings_death_boundary;
    int higher_lemmings_death_boundary;
    int left_lemmings_death_boundary;
    int right_lemmings_death_boundary;

    /**
     * Adjusts position of @param:lemming which is added in place of calling instance in case their heights are different.
     */
    void adjust_position_for_lemmings_height_difference(Lemming *lemming);
};

#endif // LEMMING_H
