#include <algorithm>
#include <numeric>
#include <utility>

namespace fp {
// map: 将输入容器转化到输出容器
inline auto map = [](const auto& container, auto&& dest, auto&& func) {
    return std::transform(
        container.begin(), container.end(),
        std::forward<decltype(dest)>(dest),
        std::forward<decltype(func)>(func)
    );
};

// reduce: 归约（折叠）
inline auto reduce = [](const auto& container, auto init, auto&& op) {
    return std::accumulate(
        container.begin(), container.end(),
        init,
        std::forward<decltype(op)>(op)
    );
};

// filter: 根据谓词，拷贝到输出容器
inline auto filter = [](const auto& container, auto&& dest, auto&& pred) {
    return std::copy_if(
        container.begin(), container.end(),
        std::forward<decltype(dest)>(dest),
        std::forward<decltype(pred)>(pred)
    );
};

// any: 是否存在某个满足条件的元素
inline auto any = [](const auto& container, auto&& pred) {
    return std::any_of(
        container.begin(), container.end(),
        std::forward<decltype(pred)>(pred)
    );
};

// all: 是否全部满足条件
inline auto all = [](const auto& container, auto&& pred) {
    return std::all_of(
        container.begin(), container.end(),
        std::forward<decltype(pred)>(pred)
    );
};

// none: 是否没有元素满足条件
inline auto none = [](const auto& container, auto&& pred) {
    return std::none_of(
        container.begin(), container.end(),
        std::forward<decltype(pred)>(pred)
    );
};

// find: 找到第一个满足条件的元素迭代器
inline auto find = [](const auto& container, auto&& pred) {
    return std::find_if(
        container.begin(), container.end(),
        std::forward<decltype(pred)>(pred)
    );
};

// count: 统计满足条件的元素个数
inline auto count = [](const auto& container, auto&& pred) {
    return std::count_if(
        container.begin(), container.end(),
        std::forward<decltype(pred)>(pred)
    );
};

// for_each: 对容器中每个元素应用函数
inline auto for_each = [](const auto& container, auto&& func) {
    return std::for_each(
        container.begin(), container.end(),
        std::forward<decltype(func)>(func)
    );
};

inline auto partition = [](const auto& container, auto&& dest_true, auto&& dest_false, auto&& pred) {
    return std::partition_copy(
        container.begin(), container.end(),
        std::forward<decltype(dest_true)>(dest_true),
        std::forward<decltype(dest_false)>(dest_false),
        std::forward<decltype(pred)>(pred)
    );
};

// 组合函数
template <typename F, typename... Rest>
auto compose(F f, Rest... rest) {
    if constexpr (sizeof...(rest) == 0) {
        return f;
    } else {
        auto g = compose(rest...);
        return [=](auto&&... args) -> decltype(auto) {
            return f(g(std::forward<decltype(args)>(args)...));
        };
    }
}
}
