package com.room.roomcreator;

public class Wall implements DecorationItem {

    public enum WallType {
        DRYWALL,
        PAINT1,
        PAINT2,
        PAINT3,
        PAINT4,
        PAINT5,
        PAINT6,
        PAINT7,
        WALLPAPER1,
        WALLPAPER2,
        WALLPAPER3,
        WALLPAPER4,
        WALLPAPER5
    }

    private WallType type;
    private double area;

    public Wall(double area, WallType type) {
        this.type = type;
        this.area = area;
    }

    public void setWallType(WallType type) {
        this.type = type;
    }

    @Override
    public double getCost(Room room) {
        switch (type) {
            case DRYWALL:
                return area * 0;
            case PAINT1:
                return area * 12.90;
            case PAINT2:
                return area * 12.90;
            case PAINT3:
                return area * 12.90;
            case PAINT4:
              return area * 12.90;
            case PAINT5:
               return area * 12.90;
            case PAINT6:
                return area * 12.90;
            case PAINT7:
                return area * 12.90;
            case WALLPAPER1:
                return area * 22.90;
            case WALLPAPER2:
                return area * 34.90;
            case WALLPAPER3:
                return area * 17.90;
            case WALLPAPER4:
                return area * 19.90;
            case WALLPAPER5:
                return area * 23.90;
            default:
                throw new IllegalStateException("Invalid wall type selected: " + type);
        }
    }

    @Override
    public String getName() {
        switch (type) {
            case DRYWALL:
                return "Tehosteeton seinä esim. paljas kipsilevy";
            case PAINT1:
                return "Tikkurila Tunne Väri 2020 Y500 Takorauta";
            case PAINT2:
                return "Tikkurila Tunne Väri 2020 X499 Lakritsi";
            case PAINT3:
                return "Tikkurila Tunne Väri 2020 L462 Sacher";
            case PAINT4:
                return "Tikkurila Tunne Väri 2020 Y344 Orvokki";
            case PAINT5:
                return "Tikkurila Tunne Väri 2020 L433 Atlantis";
            case PAINT6:
                return "Tikkurila Tunne Väri 2020 N501 Andante";
            case PAINT7:
                return "Tikkurila Tunne Väri 2020 F428 Ketju";
            case WALLPAPER1:
                return "Artgeist Granite Bastion 70 x 100";
            case WALLPAPER2:
                 return "Sandberg Linnea vaaleansininen 0,53 x 10,05";
            case WALLPAPER3:
                return "Artgeist Concrete Sky 50 x 1000";
            case WALLPAPER4:
                return "Artgeist Morning Fog 70 x 100";
            case WALLPAPER5:
                return "Vallila Kuuba 0,53 x 10,05";
            default:
                throw new IllegalStateException("Invalid wall type selected: " + type);
        }
    }

    public double getArea() {
        return area;
    }

}