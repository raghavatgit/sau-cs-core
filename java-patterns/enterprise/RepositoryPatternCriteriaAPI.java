package enterprise;

import java.util.List;

public interface RepositoryPatternCriteriaAPI<T, ID> {
    T findById(ID id);
    List<T> findAll(SpecificationRuleEngine<T> spec);
    void save(T entity);
    void delete(ID id);
}
