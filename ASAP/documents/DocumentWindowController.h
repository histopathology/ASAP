#ifndef __ASAP_DOCUMENTS_DOCUMENTWINDOWCONTROLLER__
#define __ASAP_DOCUMENTS_DOCUMENTWINDOWCONTROLLER__

#include <QObject>
#include <vector>
#include <memory>

#include "documents/DocumentInstance.h"
#include "Documents/DocumentWindow.h"
#include "PathologyViewer.h"
#include "WSITileGraphicsItemCache.h"

#include "asaplib_export.h"

namespace ASAP
{
	class ASAPLIB_EXPORT DocumentWindowController : public QObject
	{
		Q_OBJECT
		public:
			DocumentWindowController(void);

			uint64_t GetCacheSize(void) const;
			/// <summary>
			/// Changes the size of the internal cache. This operation isn't thread safe.
			/// </summary>
			/// <param name="size">The new size in bytes.</param>
			void SetCacheSize(uint64_t size);

			DocumentWindow* GetActiveWindow(void) const;
			DocumentWindow* SpawnWindow(QWidget* parent = nullptr);

		signals:
			void FocusChanged(DocumentWindow* window);

		private:
			DocumentWindow*					m_active_;
			std::vector<DocumentWindow*>	m_viewers_;
			WSITileGraphicsItemCache		m_cache_;

			void SetupSlots_(void);

		private slots:
			void OnFocusChanged_(const PathologyViewer* view);
	};
}
#endif // __ASAP_DOCUMENTS_DOCUMENTWINDOWCONTROLLER__