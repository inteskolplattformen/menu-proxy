use chrono::NaiveDate;
use munin_lib::types;

use crate::models::menu::Menu;
use crate::schema::days;
use crate::types::smaztext::SmazText;

use super::menu::MenuId;

#[derive(Identifiable, Queryable, Associations, PartialEq, Debug)]
#[belongs_to(Menu)]
#[table_name = "days"]
#[primary_key(date, menu_id)]
pub struct Day {
    pub date: NaiveDate,
    pub meals: SmazText,
    pub menu_id: MenuId,
}

#[derive(Debug, Insertable)]
#[table_name = "days"]
pub struct NewDay {
    date: NaiveDate,
    menu_id: MenuId,
    meals: SmazText,
}

impl NewDay {
    pub fn from_day(day: types::day::Day, menu_id: MenuId) -> Self {
        let meals = day
            .meals
            .into_iter()
            .map(|m| m.value)
            .collect::<Vec<_>>()
            .join("\n");

        Self {
            date: day.date,
            menu_id,
            meals: meals.into(),
        }
    }
}

impl From<Day> for types::day::Day {
    fn from(d: Day) -> Self {
        Self {
            date: d.date,
            meals: d.meals.into(),
        }
    }
}
