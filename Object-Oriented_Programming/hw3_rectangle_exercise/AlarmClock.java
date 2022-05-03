public class AlarmClock 
{
    /* attribute (instance variables) */

    private int hour;
    private int minute;
    private int second;

    private int alarmHour;
    private int alarmMinute;
    private int alarmSecond;

    /* Constructor */

    public AlarmClock()
    {
        this(0, 0, 0);
    }

    public AlarmClock(int h, int m, int s)
    {
        setTime(h, m, s);
    }

    public void setTime(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }

    public void setAlarmTime(int h, int m, int s)
    {
        alarmHour = h;
        alarmMinute = m;
        alarmSecond = s;
    }

    public void printTime()
    {
        System.out.println(hour + ":" + minute + ":" + second);
    }

    public void printAlarmTime()
    {
        System.out.println(alarmHour + ":" + alarmMinute + ":" + alarmSecond);
    }

    /* add one second to the time now */
    public boolean checkAlarm()
    {
        return (hour == alarmHour) && (minute == alarmMinute)
            && (second == alarmSecond);
    }

    public void printCheckAlarm()
    {
        if (checkAlarm() == true)
        {
            System.out.println("Alarm!!!");
        }
        else
        {
            System.out.println("zzzzz");
        }
    }

    public void tick()
    {
        second = second + 1;

        if (second >= 60)
        {
            minute = minute + 1;
            second = 0;
        }

        if (minute >= 60)
        {
            hour = hour + 1;
            minute = 0;
        }
   
        if (hour >= 24)
        {
            hour = 0;
        }
    }

    /* getter and setters */
    public int getHour()
    {
        return hour;
    }

    public int getMinute()
    {
        return minute;
    }

    public int getSecond()
    {
        return second;
    }

    public void setHour(int hour)
    {
        this.hour = hour;
    }

    public void setMinute(int updateMinute)
    {
        minute = updateMinute;
    }

    public void setSecond(int updateSecond)
    {
        second = updateSecond;
    }

    /* overRIDES toString() method in Object class */
    public String toString()
    {
        return hour + ":" + minute + ":" + second;
    }
}
