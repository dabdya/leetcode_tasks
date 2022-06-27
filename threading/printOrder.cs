using System.Threading;

public class Foo {
    
    private readonly AutoResetEvent first;
    private readonly AutoResetEvent second;
    
    public Foo() {
        first = new AutoResetEvent(false);
        second = new AutoResetEvent(false);
    }
    
    public void First(Action printFirst) {
        
        printFirst();
        first.Set();
    }

    public void Second(Action printSecond) {
        
        first.WaitOne();
        printSecond();
        second.Set();

    }

    public void Third(Action printThird) {
        
        second.WaitOne();
        printThird();
        
    }
}


/*
    AutoResetEvent - инструмент синхронизации потоков, объект которого может быть
    в сигнальном и несигнальном состоянии. Сигнальное состояние обозначает готовность
    быть захваченным, несигнальное предотвращает захват пока объект не будет освобожде.
        
        1. WaitOne - задает несигнальное состояние и блокирует текущий поток
        2. Set - задает сигнальное состояние
        3. Reset - задает несигнальное состояние
*/
