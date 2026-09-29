package org.sau.core;

import java.util.concurrent.Flow;

public class ReactivePublisher implements Flow.Publisher<String> {
    public void subscribe(Flow.Subscriber<? super String> subscriber) {
        subscriber.onSubscribe(new Flow.Subscription() {
            public void request(long n) {
                subscriber.onNext("DATA_PACKET");
                subscriber.onComplete();
            }
            public void cancel() {}
        });
    }
}
