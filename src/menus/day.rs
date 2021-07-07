use std::collections::HashSet;

use chrono::NaiveDate;
use serde::Serialize;

use super::meal::Meal;

#[derive(Serialize, Debug, PartialEq, Eq, PartialOrd, Ord)]
pub struct Day {
    /// Time zones aren't really relevant here.
    pub date: NaiveDate,
    pub meals: Vec<Meal>,
}

/// Remove duplicate dates from a vector.
/// ```
/// use chrono::NaiveDate;
/// use menu_proxy::menus::day::{Day, dedup_dates};
/// use menu_proxy::menus::meal::Meal;
///
/// let mut days = vec![
///   Day {
///     date: NaiveDate::from_ymd(1789, 7, 14),
///     meals: vec![Meal {
///         value: "Tacos".to_owned(),
///     }],
/// },
/// Day {
///     date: NaiveDate::from_ymd(1789, 7, 14),
///     meals: vec![Meal {
///         value: "Sushi".to_owned(),
///     }],
/// },
/// ];
///
/// dedup_dates(&mut days);
///
/// assert_eq!(
/// days,
/// [Day {
///     date: NaiveDate::from_ymd(1789, 7, 14),
///     meals: vec![Meal {
///         value: "Tacos".to_owned(),
///     }]
/// }]
/// )
/// ```
pub fn dedup_dates(days: &mut Vec<Day>) {
    let mut seen_dates = HashSet::<NaiveDate>::new();
    days.retain(|day| seen_dates.insert(day.date));
}
