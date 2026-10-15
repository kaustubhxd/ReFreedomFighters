"""specs_s66034.py - cascade s4 batch 66034: 0x426c50 (enumerate the files of a directory and report each name)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g426c50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    base = e.alloc(0x40, 8)
    e.wbytes(base, r.choice([b'', b'C:\\x', b'dir']) + b'\0')
    so = sysobj(c)
    e.w32(so + 0x123, base)
    names = [r.choice([b'.', b'..', b'...', b'.a', b'a.b', b'..x', b'file']) for _ in range(r.choice([0, 1, 2, 4]))]
    first_ok = r.random() < 0.85
    state = {'i': 0}

    def putname(em, fd, i):
        em.wbytes(fd + 0x2c, names[i] + b'\0')

    def ff(em, rr):                       # FindFirstFileA (path, &fd)
        path, fd = em.arg32(0), em.arg32(1)
        s = bytes(em.rbytes(path, 40)).split(b'\0')[0]
        em.calllog.append(('FindFirst', s))
        if not first_ok or not names:
            em.ret(eax=0xffffffff, argbytes=8)
            return
        state['i'] = 0
        putname(em, fd, 0)
        em.ret(eax=0x5151, argbytes=8)

    def fn(em, rr):                       # FindNextFileA (h, &fd)
        h, fd = em.arg32(0), em.arg32(1)
        state['i'] += 1
        em.calllog.append(('FindNext', h, state['i']))
        if state['i'] < len(names):
            putname(em, fd, state['i'])
            em.ret(eax=1, argbytes=8)
        else:
            em.ret(eax=0, argbytes=8)

    def fc(em, rr):
        em.calllog.append(('FindClose', em.arg32(0)))
        em.ret(eax=1, argbytes=4)
    e.stub_import('FindFirstFileA', ff)
    e.stub_import('FindNextFileA', fn)
    e.stub_import('FindClose', fc)

    def tr(em, rr):                       # this->slot 0x4c (path)
        s = bytes(em.rbytes(em.arg32(0), 40)).split(b'\0')[0]
        em.calllog.append(('slot4c', s))
        em.ret(eax=0, argbytes=4)

    def rep(em, rr):                      # c->slot 0x88 (name)
        s = bytes(em.rbytes(em.arg32(0), 16)).split(b'\0')[0]
        em.calllog.append(('report', s))
        em.ret(eax=0, argbytes=4)
    t = obj(c, 0x30, {0x4c: e.stub_fn('slot4c', tr)})
    cobj = obj(c, 0x30, {0x88: e.stub_fn('report', rep)})
    return [t, r.getrandbits(32), r.getrandbits(32), cobj]


S(0x426c50, 'GUESS enumerate a directory and report each name', 'thiscall', None, ret=None, gen=_g426c50, note='batch66034')
