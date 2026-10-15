"""specs_s37113.py - cascade s6 batch 37113 (0x4d6400, thiscall(), returns eax). The stream object at +0x15 is a simulated in-memory file: slots 0x10 (seek h, off, whence), 0xc (tell h)
and 0x14 (read buf, size, h) operate on a Python byte string with a position, and log every call (stack buffers as markers). The file holds random bytes with planted end-record
signatures (0x6054b50) and 'enuR' markers (0x52756e65) at random positions; short files (< 0x16 bytes) return -1 at once. The assert hook is always set."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _g4d6400(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    L = r.choice([0, 5, 0x15, 0x16, 0x17, 0x20, 0x30, 0x50, 0x90])
    data = bytearray(r.getrandbits(8) for _ in range(L))
    for _ in range(r.choice([0, 1, 1, 2, 3])):
        if L >= 4:
            p = r.randrange(0, L - 3)
            data[p:p + 4] = (0x6054b50).to_bytes(4, 'little') if r.random() < 0.5 else (0x52756e65).to_bytes(4, 'little')
    state = {'pos': 0}
    big = 0x7fffffff

    def sd(v):
        return v - (1 << 32) if v & 0x80000000 else v

    def seek(em, res_):
        h, off, wh = em.arg32(0), sd(em.arg32(1)), em.arg32(2)
        em.calllog.append(('seek', h, off, wh))
        base = 0 if wh == 0 else (state['pos'] if wh == 1 else len(data))
        state['pos'] = max(0, base + off)
        em.ret(eax=0, argbytes=12)

    def tell(em, res_):
        em.calllog.append(('tell', em.arg32(0), state['pos']))
        em.ret(eax=state['pos'], argbytes=4)

    def read(em, res_):
        buf, n, h = em.arg32(0), em.arg32(1), em.arg32(2)
        chunk = bytes(data[state['pos']:state['pos'] + n])
        if 0x20000000 <= buf < 0x30000000:
            em.wbytes(buf, chunk)
        else:
            em.wbytes(buf, chunk)
        em.calllog.append(('read', buf if 0x20000000 <= buf < 0x30000000 else 1, n, h, chunk))
        state['pos'] += len(chunk)
        em.ret(eax=len(chunk), argbytes=12)
    ms = obj(c, 0x20, {0x10: e.stub_fn('seek', seek), 0xc: e.stub_fn('tell', tell), 0x14: e.stub_fn('read', read)})
    t = rnd(c, 0x60)
    e.wbytes(t + 0x15, ms.to_bytes(4, 'little'))
    e.wbytes(t + 0x11, r.getrandbits(32).to_bytes(4, 'little'))
    return [t]


S(0x4d6400, 'GUESS find_end_record', 'thiscall', None, ret='eax', gen=_g4d6400, note='batch37113')
