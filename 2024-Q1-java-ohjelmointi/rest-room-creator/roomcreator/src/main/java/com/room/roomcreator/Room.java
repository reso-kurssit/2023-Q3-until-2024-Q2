package com.room.roomcreator;

import java.util.ArrayList;
import java.util.List;

import com.room.roomcreator.Floor.FloorType;
import com.room.roomcreator.Wall.WallType;

public class Room {

    private double width;
    private double length;
    private double height;
    private Floor floor = new Floor(FloorType.BASEFLOOR);
    private List <Wall> walls = new ArrayList<>();

    public Room(double width, double length, double height, double budget) {
        this.width = width;
        this.length = length;
        this.height = height;
        walls.add(new Wall(width * height, WallType.DRYWALL));
        walls.add(new Wall(width * height, WallType.DRYWALL));
        walls.add(new Wall(length * height, WallType.DRYWALL));
        walls.add(new Wall(length * height, WallType.DRYWALL));
    }

    public void updateFloor(FloorType type) {
        floor.setFloorType(type);
    }

    public void updateWall(int wallIndex, Wall.WallType newType) {
        if (wallIndex >= 0 && wallIndex < walls.size()) {
            Wall existingWall = walls.get(wallIndex);
            existingWall.setWallType(newType);
        } else {
            throw new IndexOutOfBoundsException("Invalid wall index: " + wallIndex);
        }
    }

    public Floor getFloor() {
        return floor;
    }

    public List <Wall> getWalls() {
        return walls;
    }

    public double getWidth() {
        return this.width;
    }

    public double getLength() {
        return this.length;
    }

    public double getArea() {
        return width * length;
    }

    public double getHeight() {
        return height;
    }

    public double getCost() {
        double cost = floor.getCost(this);
        for (Wall wall : walls) {
            cost += wall.getCost(this);
        }

        return cost;
    }

}
