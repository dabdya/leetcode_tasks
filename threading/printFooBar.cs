using System.Threading;

public class FooBar {
    private int n;
    
    private readonly AutoResetEvent foo;
    private readonly AutoResetEvent bar;

    public FooBar(int n) {
        this.n = n;
        
        foo = new AutoResetEvent(false);
        bar = new AutoResetEvent(true);
    }

    public void Foo(Action printFoo) {
        
        for (int i = 0; i < n; i++) {
            
            bar.WaitOne();
        	printFoo();
            foo.Set();
        }
    }

    public void Bar(Action printBar) {
        
        for (int i = 0; i < n; i++) {
            
            foo.WaitOne();
        	printBar();
            bar.Set();
        }
    }
}
