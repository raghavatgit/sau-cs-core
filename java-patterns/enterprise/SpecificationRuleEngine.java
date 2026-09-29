package enterprise;

public interface SpecificationRuleEngine<T> {
    boolean isSatisfiedBy(T candidate);

    default SpecificationRuleEngine<T> and(SpecificationRuleEngine<T> other) {
        return candidate -> isSatisfiedBy(candidate) && other.isSatisfiedBy(candidate);
    }
}
