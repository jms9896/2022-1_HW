public class AlarmClockRunner
{
    public AlarmClockRunner()
    {

    }

    public static void main(String[] args)
    {
        AlarmClock clock = new AlarmClock();
        clock.printTime();

        AlarmClock myClock = new AlarmClock(1, 20, 0);
        myClock.printTime();
        myClock.tick();
        myClock.printTime();
        myClock.tick();
        myClock.printTime();
        myClock.tick();
        myClock.printTime();

        myClock.setTime(3, 59, 59);
        myClock.printTime();
        myClock.tick();
        myClock.printTime();
        
        myClock.setAlarmTime(4, 0, 0);
        myClock.printCheckAlarm();
    }
}
