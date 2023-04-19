// AUTOGENERATED COPYRIGHT HEADER START
// Copyright (C) 2020-2023 Michael Fabian 'Xaymar' Dirks <info@xaymar.com>
// AUTOGENERATED COPYRIGHT HEADER END

#include "ui-about-entry.hpp"

constexpr std::string_view i18n_role_contributor = "UI.About.Role.Contributor";
constexpr std::string_view i18n_role_translator  = "UI.About.Role.Translator";
constexpr std::string_view i18n_role_supporter   = "UI.About.Role.Supporter";

streamfx::ui::about_entry::about_entry(QWidget* parent, const streamfx::ui::about::entry& entry)
	: QWidget(parent), _link()
{
	setupUi(this);

	name->setText(QString::fromStdString(entry.name));
	switch (entry.role) {
	case streamfx::ui::about::role_type::NONE:
		title->setText(QString::fromStdString(entry.role_custom));
		break;
	case streamfx::ui::about::role_type::CONTRIBUTOR:
		title->setText(D_TRANSLATE(i18n_role_contributor.data()));
		break;
	case streamfx::ui::about::role_type::TRANSLATOR:
		title->setText(D_TRANSLATE(i18n_role_translator.data()));
		break;
	case streamfx::ui::about::role_type::SUPPORTER:
		title->setText(D_TRANSLATE(i18n_role_supporter.data()));
		break;
	default:
		break;
	}

	if (!entry.link.empty()) {
		this->setCursor(Qt::PointingHandCursor);
		_link = QUrl(QString::fromUtf8(entry.link.c_str()));
	}
}

streamfx::ui::about_entry::~about_entry() {}

void streamfx::ui::about_entry::mousePressEvent(QMouseEvent* event)
{
	if (_link.isEmpty())
		return;

	if (event->button() == Qt::LeftButton) {
		QDesktopServices::openUrl(_link);
	}
}
