"""specs_s66033.py - cascade s4 batch 66033: 0x425f80 (formatted log line sent to the console and a window)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g425f80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    texts = [b'', b'x', b'hello\n', b'hello', b'a\n\n', b'ab']
    txt = r.choice(texts)
    obj = e.alloc(0x40, 8)

    def vs(em, rr):                       # 0x42abee (buf, fmt, va) cdecl
        buf, fmt, va = em.arg32(0), em.arg32(1), em.arg32(2)
        v0 = em.r32(va)
        em.calllog.append(('vsprintf', fmt, v0, em.rbytes(obj + 0x12, 1)[0]))
        em.wbytes(buf, txt + b'\0')
        em.ret(eax=len(txt), argbytes=0)
    e.hook(0x42abee, vs)

    def pr(em, rr):                       # 0x42ab62 (s) cdecl
        em.calllog.append(('print', bytes(em.rbytes(em.arg32(0), 12))))
        em.ret(eax=0, argbytes=0)
    e.hook(0x42ab62, pr)

    def iob(em, rr):
        em.calllog.append(('iob', em.arg32(0)))
        em.ret(eax=0x1234, argbytes=0)

    def ff(em, rr):
        em.calllog.append(('fflush', em.arg32(0)))
        em.ret(eax=0, argbytes=0)

    def sm(em, rr):                       # SendMessageA (wnd, msg, wparam, &cds) stdcall
        w, m, wp, cds = em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3)
        n = em.r32(cds + 4)
        em.calllog.append(('SendMessage', w, m, wp, em.r32(cds), n, bytes(em.rbytes(em.r32(cds + 8), min(n, 16)))))
        em.ret(eax=1, argbytes=16)
    e.stub_import('__acrt_iob_func', iob)
    e.stub_import('fflush', ff)
    e.stub_import('SendMessageA', sm)
    e.wbytes(obj, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.wbytes(obj + 0x12, bytes([r.choice([0, 0, 0, 1])]))
    e.w32(obj + 0x24, r.choice([0, 0x4242]))
    e.wbytes(0x676c04, b'\n\0')
    e._image_dirty = True
    return [obj, rnd(c, 8), r.getrandbits(32), r.getrandbits(32)]


S(0x425f80, 'GUESS formatted log line to console and window', 'cdecl', None, ret=None, gen=_g425f80, note='batch66033')
