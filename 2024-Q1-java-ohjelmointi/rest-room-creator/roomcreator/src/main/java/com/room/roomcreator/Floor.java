package com.room.roomcreator;

public class Floor implements DecorationItem {

    public enum FloorType{
        BASEFLOOR,
        LAMINATE1,
        LAMINATE2,
        LAMINATE3,
        LAMINATE4,
        LAMINATE5,
        WOOD1,
        WOOD2,
        WOOD3,
        WOOD4,
        WOOD5,
        TILE1,
        TILE2,
        TILE3,
        TILE4,
        TILE5,
        TILE6,
        TILE7
    }

    private FloorType type;
    
    public Floor(FloorType type) {
        this.type = type;
    }

    @Override
    public double getCost(Room room) {
        switch (type) {
            case BASEFLOOR:
                return room.getArea() * 0;
            case LAMINATE1:
                return room.getArea() * 19.90;
            case LAMINATE2:
                return room.getArea() * 27.90;
            case LAMINATE3:
                return room.getArea() * 9.60;
            case LAMINATE4:
                return room.getArea() * 12.90;
            case LAMINATE5:
                return room.getArea() * 39.30;
            case WOOD1:
                return room.getArea() * 34.90;
            case WOOD2:
                return room.getArea() * 39.90;
            case WOOD3:
                return room.getArea() * 97.30;
            case WOOD4:
                return room.getArea() * 112.70;
            case WOOD5:
                return room.getArea() * 34.90;
            case TILE1:
                return room.getArea() * 26.90;
            case TILE2:
                return room.getArea() * 34.90;
            case TILE3:
                return room.getArea() * 36.50;
            case TILE4:
                return room.getArea() * 36.90;
            case TILE5:
                return room.getArea() * 62.90;
            case TILE6:
                return room.getArea() * 55.90;
            case TILE7:
                return room.getArea() * 139.90;
            default:
                throw new IllegalStateException("Invalid floor type selected: " + type);
        }
    }

    @Override
    public String getName() {

        switch (type) {
            case BASEFLOOR:
                return "Lattiavalu, ei päällystettä";
            case LAMINATE1:
                return "Pergo Natural Honey Oak";
            case LAMINATE2:
                return "Upofloor Vitality Deluxe, Moraine Natural Oak";
            case LAMINATE3:
                return "Kronoflooring Premium Smugglers Cove";
            case LAMINATE4:
                return "Kronoflooring Premium St.Misty";
            case LAMINATE5:
                return "Pergo Trondheim Fresh Nordic Oak";
            case WOOD1:
                return "Karelia Tammi Pecan 3S";
            case WOOD2:
                return "Nordic Floor Villa Tammi";
            case WOOD3:
                return "Pergo Lofoten Light Pure Oak";
            case WOOD4:
                return "Pergo Saltholm Natural Herringbone Oak";
            case WOOD5:
                return "Karelia Tammi Dacite Grey 3S";
            case TILE1:
                return "Cello Kaya Rustic 9,7 x 9,7";
            case TILE2:
                return "Cello Assen 10 x 10";
            case TILE3:
                return "Taiga antrasiitti 9,7 x 9,7";
            case TILE4:
                return "Cello Saaga ruskea 9,7 x 9,7";
            case TILE5:
                return "Cello Cr.Rovere hunaja 15 x 90";
            case TILE6:
                return "Cello Appeal antrasiitti 30 x 60";
            case TILE7:
                return "Golden White Lux 60 x 120";
            default:
                throw new IllegalStateException("Invalid floor type selected: " + type);
        }

    }

    public void setFloorType(FloorType type) {
        this.type = type;
    }

}
